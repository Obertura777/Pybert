// sub_438b30 @ 0x438b30
// hopper name: sub_438b30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_438b30() {
    decomp_var_c = *0x0;
    decomp_var_70 = ebx;
    decomp_var_74 = ebp;
    decomp_var_78 = esi;
    decomp_var_7c = edi;
    esp = esp - 0x80;
    decomp_var_80 = *dword_4c8db8 ^ &decomp_var_7c;
    *0x0 = &decomp_var_c;
    esi = ecx;
    decomp_var_69 = 0x0;
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_60 = (*(*eax + 0xc))() + 0x10;
            edx = esi[0x2];
            ebx = arg_0;
            decomp_var_64 = edx[0x1212];
            ecx = edx[0x2424] & 0xff;
            if (ebx != ecx) {
                    if ((*(ebx * 0x8 + 0x4d53d8) | *(ebx * 0x8 + 0x4d53dc)) == 0x0) {
                            edi = ecx * 0x15 + ebx;
                            if ((*(edi * 0x8 + 0x4d5528) | *(edi * 0x8 + 0x4d552c)) == 0x0) {
                                    if (*(int8_t *)byte_baed68 != 0x1) {
                                            if ((*((ebx * 0x15 + ecx) * 0x8 + 0x4d5528) | *((ebx * 0x15 + ecx) * 0x8 + 0x4d552c)) == 0x0) {
                                                    eax = *(ebx * 0x8 + 0x4cf568);
                                                    eax = eax | *(ebx * 0x8 + 0x4cf56c);
                                                    if (eax == 0x0) {
                                                            asm { fldz };
                                                            asm { fcomp      qword [dword_633f14+5573172+edi*8] };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    if (*(edi * 0x4 + 0x634e90) >= 0x0) {
                                                                            if (*(int16_t *)word_4c6cc4 == edx[0x1225]) {
                                                                                    edx = &decomp_var_4c;
                                                                                    esp = esp - 0xc;
                                                                                    decomp_var_5c = (ebx + ebx * 0x2) * 0x4 + 0xbb6e10;
                                                                                    eax = sub_4108a0(edx, word_4c6dc4, &decomp_var_5c, decomp_var_80, decomp_var_7c);
                                                                                    eax = sub_401050(decomp_var_84);
                                                                                    if (eax != 0x0) {
                                                                                            asm { fld        qword [aWeThoughtWeWer+64] };
                                                                                            asm { fcomp      qword [dword_633f14+5573172+edi*8] };
                                                                                            asm { fnstsw     ax };
                                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                    if (*(edi * 0x4 + 0x6340c0) > 0x3) {
                                                                                                            if (*dword_baed64 > 0x1) {
                                                                                                                    *(ebx * 0x8 + 0x4d53d8) = 0x1;
                                                                                                                    *(ebx * 0x8 + 0x4d53dc) = 0x0;
                                                                                                                    decomp_var_68 = ebx & 0xff | 0x4100;
                                                                                                                    eax = sub_466540(&decomp_var_1c, &decomp_var_68);
                                                                                                                    eax = sub_466f80(&decomp_var_5c, eax);
                                                                                                                    eax = sub_466f80(&decomp_var_4c, eax);
                                                                                                                    sub_465ff0(eax);
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465f30(&decomp_var_68);
                                                                                                                    sub_465ff0(&decomp_var_4c);
                                                                                                                    sub_465fa0();
                                                                                                                    edx = &decomp_var_3c;
                                                                                                                    sub_465f60(edx);
                                                                                                                    esp = esp - 0x4c;
                                                                                                                    eax = sub_465f60(&decomp_var_2c);
                                                                                                                    sub_431940();
                                                                                                                    eax = decomp_var_60 - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                    if (edx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                    }
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0x1;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ebx = decomp_var_69;
                                                                                                                    eax = decomp_var_60 - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                                    if (edx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                    }
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = ebx;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            *(ebx * 0x8 + 0x4d53d8) = 0x1;
                                                                                                            *(ebx * 0x8 + 0x4d53dc) = 0x0;
                                                                                                            decomp_var_68 = ebx & 0xff | 0x4100;
                                                                                                            eax = sub_466540(&decomp_var_1c, &decomp_var_68);
                                                                                                            eax = sub_466f80(&decomp_var_5c, eax);
                                                                                                            eax = sub_466f80(&decomp_var_4c, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465f30(&decomp_var_68);
                                                                                                            sub_465ff0(&decomp_var_4c);
                                                                                                            sub_465fa0();
                                                                                                            edx = &decomp_var_3c;
                                                                                                            sub_465f60(edx);
                                                                                                            esp = esp - 0x4c;
                                                                                                            eax = sub_465f60(&decomp_var_2c);
                                                                                                            sub_431940();
                                                                                                            eax = decomp_var_60 - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                            if (edx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                            }
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0x1;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    *(ebx * 0x8 + 0x4d53d8) = 0x1;
                                                                                                    *(ebx * 0x8 + 0x4d53dc) = 0x0;
                                                                                                    decomp_var_68 = ebx & 0xff | 0x4100;
                                                                                                    eax = sub_466540(&decomp_var_1c, &decomp_var_68);
                                                                                                    eax = sub_466f80(&decomp_var_5c, eax);
                                                                                                    eax = sub_466f80(&decomp_var_4c, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465f30(&decomp_var_68);
                                                                                                    sub_465ff0(&decomp_var_4c);
                                                                                                    sub_465fa0();
                                                                                                    edx = &decomp_var_3c;
                                                                                                    sub_465f60(edx);
                                                                                                    esp = esp - 0x4c;
                                                                                                    eax = sub_465f60(&decomp_var_2c);
                                                                                                    sub_431940();
                                                                                                    eax = decomp_var_60 - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                    }
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0x1;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = decomp_var_69;
                                                                                            eax = decomp_var_60 - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    (*(**eax + 0x4))(eax);
                                                                                            }
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = ebx;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = decomp_var_69;
                                                                                    eax = decomp_var_60 - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            (*(**eax + 0x4))(eax);
                                                                                    }
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = decomp_var_69;
                                                                            eax = decomp_var_60 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = decomp_var_69;
                                                                    eax = decomp_var_60 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                    }
                                                    else {
                                                            ebx = decomp_var_69;
                                                            eax = decomp_var_60 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = ebx;
                                                            *0x0 = decomp_var_c;
                                                    }
                                            }
                                            else {
                                                    ebx = decomp_var_69;
                                                    eax = decomp_var_60 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = ebx;
                                                    *0x0 = decomp_var_c;
                                            }
                                    }
                                    else {
                                            eax = *(ebx * 0x8 + 0x4cf568);
                                            eax = eax | *(ebx * 0x8 + 0x4cf56c);
                                            if (eax == 0x0) {
                                                    asm { fldz };
                                                    asm { fcomp      qword [dword_633f14+5573172+edi*8] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            if (*(edi * 0x4 + 0x634e90) >= 0x0) {
                                                                    if (*(int16_t *)word_4c6cc4 == edx[0x1225]) {
                                                                            edx = &decomp_var_4c;
                                                                            esp = esp - 0xc;
                                                                            decomp_var_5c = (ebx + ebx * 0x2) * 0x4 + 0xbb6e10;
                                                                            eax = sub_4108a0(edx, word_4c6dc4, &decomp_var_5c, decomp_var_80, decomp_var_7c);
                                                                            eax = sub_401050(decomp_var_84);
                                                                            if (eax != 0x0) {
                                                                                    asm { fld        qword [aWeThoughtWeWer+64] };
                                                                                    asm { fcomp      qword [dword_633f14+5573172+edi*8] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            if (*(edi * 0x4 + 0x6340c0) > 0x3) {
                                                                                                    if (*dword_baed64 > 0x1) {
                                                                                                            *(ebx * 0x8 + 0x4d53d8) = 0x1;
                                                                                                            *(ebx * 0x8 + 0x4d53dc) = 0x0;
                                                                                                            decomp_var_68 = ebx & 0xff | 0x4100;
                                                                                                            eax = sub_466540(&decomp_var_1c, &decomp_var_68);
                                                                                                            eax = sub_466f80(&decomp_var_5c, eax);
                                                                                                            eax = sub_466f80(&decomp_var_4c, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465f30(&decomp_var_68);
                                                                                                            sub_465ff0(&decomp_var_4c);
                                                                                                            sub_465fa0();
                                                                                                            edx = &decomp_var_3c;
                                                                                                            sub_465f60(edx);
                                                                                                            esp = esp - 0x4c;
                                                                                                            eax = sub_465f60(&decomp_var_2c);
                                                                                                            sub_431940();
                                                                                                            eax = decomp_var_60 - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                            if (edx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                            }
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0x1;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                                    else {
                                                                                                            ebx = decomp_var_69;
                                                                                                            eax = decomp_var_60 - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                            if (edx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                            }
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = ebx;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    *(ebx * 0x8 + 0x4d53d8) = 0x1;
                                                                                                    *(ebx * 0x8 + 0x4d53dc) = 0x0;
                                                                                                    decomp_var_68 = ebx & 0xff | 0x4100;
                                                                                                    eax = sub_466540(&decomp_var_1c, &decomp_var_68);
                                                                                                    eax = sub_466f80(&decomp_var_5c, eax);
                                                                                                    eax = sub_466f80(&decomp_var_4c, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465f30(&decomp_var_68);
                                                                                                    sub_465ff0(&decomp_var_4c);
                                                                                                    sub_465fa0();
                                                                                                    edx = &decomp_var_3c;
                                                                                                    sub_465f60(edx);
                                                                                                    esp = esp - 0x4c;
                                                                                                    eax = sub_465f60(&decomp_var_2c);
                                                                                                    sub_431940();
                                                                                                    eax = decomp_var_60 - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                                    if (edx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                    }
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0x1;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            *(ebx * 0x8 + 0x4d53d8) = 0x1;
                                                                                            *(ebx * 0x8 + 0x4d53dc) = 0x0;
                                                                                            decomp_var_68 = ebx & 0xff | 0x4100;
                                                                                            eax = sub_466540(&decomp_var_1c, &decomp_var_68);
                                                                                            eax = sub_466f80(&decomp_var_5c, eax);
                                                                                            eax = sub_466f80(&decomp_var_4c, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465f30(&decomp_var_68);
                                                                                            sub_465ff0(&decomp_var_4c);
                                                                                            sub_465fa0();
                                                                                            edx = &decomp_var_3c;
                                                                                            sub_465f60(edx);
                                                                                            esp = esp - 0x4c;
                                                                                            eax = sub_465f60(&decomp_var_2c);
                                                                                            sub_431940();
                                                                                            eax = decomp_var_60 - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            if (edx <= 0x1) {
                                                                                                    esp = esp - 0x4;
                                                                                                    (*(**eax + 0x4))(eax);
                                                                                            }
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0x1;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = decomp_var_69;
                                                                                    eax = decomp_var_60 - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    if (edx <= 0x1) {
                                                                                            esp = esp - 0x4;
                                                                                            (*(**eax + 0x4))(eax);
                                                                                    }
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = decomp_var_69;
                                                                            eax = decomp_var_60 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = decomp_var_69;
                                                                    eax = decomp_var_60 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                    }
                                                    else {
                                                            ebx = decomp_var_69;
                                                            eax = decomp_var_60 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = ebx;
                                                            *0x0 = decomp_var_c;
                                                    }
                                            }
                                            else {
                                                    ebx = decomp_var_69;
                                                    eax = decomp_var_60 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = ebx;
                                                    *0x0 = decomp_var_c;
                                            }
                                    }
                            }
                            else {
                                    ebx = decomp_var_69;
                                    eax = decomp_var_60 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = ebx;
                                    *0x0 = decomp_var_c;
                            }
                    }
                    else {
                            ebx = decomp_var_69;
                            eax = decomp_var_60 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**eax + 0x4))(eax);
                            }
                            sub_465fa0();
                            sub_465fa0();
                            eax = ebx;
                            *0x0 = decomp_var_c;
                    }
            }
            else {
                    ebx = decomp_var_69;
                    eax = decomp_var_60 - 0x10;
                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                    if (edx <= 0x1) {
                            esp = esp - 0x4;
                            (*(**eax + 0x4))(eax);
                    }
                    sub_465fa0();
                    sub_465fa0();
                    eax = ebx;
                    *0x0 = decomp_var_c;
            }
    }
    return eax;
}
