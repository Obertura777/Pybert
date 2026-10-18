// sub_42c040 @ 0x42c040
// hopper name: sub_42c040
// contains unmarked entry 0x42c160
// contains unmarked entry 0x42c730 (STABBED)
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_42c040() {
    decomp_var_c = *0x0;
    decomp_var_58 = ebx;
    decomp_var_5c = esi;
    decomp_var_60 = edi;
    esp = esp - 0x64;
    decomp_var_64 = *dword_4c8db8 ^ &decomp_var_60;
    *0x0 = &decomp_var_c;
    edi = ecx;
    esi = arg_0;
    *(int16_t *)esi = 0x0;
    sub_465870();
    sub_465870();
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_54 = (*(*eax + 0xc))() + 0x10;
            decomp_var_68 = 0x0;
            esp = esp - 0x8;
            decomp_var_6c = &arg_0;
            if (*(int16_t *)word_4c6dc4 != *(int16_t *)sub_465900(decomp_var_6c, 0x0)) {
                    eax = sub_465f60(&arg_18);
                    decomp_var_78 = ecx;
                    decomp_var_78 = arg_14;
                    eax = sub_465f60(&arg_4);
                    esp = esp - 0x30;
                    eax = sub_40d1a0(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44);
                    ecx = *(int16_t *)eax & 0xffff;
                    *(int16_t *)esi = ecx;
            }
            else {
                    decomp_var_68 = 0x0;
                    esp = esp - 0x8;
                    decomp_var_6c = &arg_0;
                    if (*(int16_t *)word_4c6d94 != *(int16_t *)sub_465900(decomp_var_6c, 0x0)) {
                            eax = sub_465f60(&arg_18);
                            decomp_var_78 = ecx;
                            decomp_var_78 = arg_14;
                            eax = sub_465f60(&arg_4);
                            esp = esp - 0x30;
                            eax = sub_41f090(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44);
                            ecx = *(int16_t *)eax & 0xffff;
                            *(int16_t *)esi = ecx;
                    }
                    else {
                            decomp_var_68 = 0x0;
                            esp = esp - 0x8;
                            decomp_var_6c = &arg_0;
                            if (*(int16_t *)word_4c6d88 != *(int16_t *)sub_465900(decomp_var_6c, 0x0)) {
                                    eax = sub_465f60(&arg_18);
                                    decomp_var_78 = ecx;
                                    decomp_var_78 = arg_14;
                                    eax = sub_465f60(&arg_4);
                                    esp = esp - 0x30;
                                    eax = sub_41e2d0(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44);
                                    ecx = *(int16_t *)eax & 0xffff;
                                    *(int16_t *)esi = ecx;
                            }
                            else {
                                    esp = esp - 0x8;
                                    eax = sub_465900(&arg_0, 0x0);
                                    if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                                            eax = sub_465f60(&arg_18);
                                            esp = esp - 0x18;
                                            decomp_var_78 = ecx;
                                            decomp_var_78 = arg_14;
                                            edx = &arg_4;
                                            sub_465f60(edx);
                                            esp = esp - 0x18;
                                            ecx = *(int16_t *)sub_426350() & 0xffff;
                                            *(int16_t *)esi = ecx;
                                    }
                                    else {
                                            decomp_var_68 = 0x0;
                                            esp = esp - 0x8;
                                            decomp_var_6c = &arg_0;
                                            if (*(int16_t *)word_4c6d30 != *(int16_t *)sub_465900(decomp_var_6c, 0x0)) {
                                                    eax = sub_465f60(&arg_18);
                                                    decomp_var_78 = ecx;
                                                    decomp_var_78 = arg_14;
                                                    eax = sub_465f60(&arg_4);
                                                    esp = esp - 0x30;
                                                    eax = sub_41ea20(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c);
                                                    ecx = *(int16_t *)eax & 0xffff;
                                                    *(int16_t *)esi = ecx;
                                            }
                                            else {
                                                    decomp_var_68 = 0x0;
                                                    esp = esp - 0x8;
                                                    decomp_var_6c = &arg_0;
                                                    if (*(int16_t *)word_4c6cdc != *(int16_t *)sub_465900(decomp_var_6c, 0x0)) {
                                                            eax = sub_465f60(&arg_18);
                                                            decomp_var_78 = ecx;
                                                            decomp_var_78 = arg_14;
                                                            eax = sub_465f60(&arg_4);
                                                            esp = esp - 0x30;
                                                            eax = sub_41ed30(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c);
                                                            ecx = *(int16_t *)eax & 0xffff;
                                                            *(int16_t *)esi = ecx;
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            eax = sub_465900(&arg_0, 0x0);
                                                            if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                                                                    eax = sub_465ff0(&arg_4);
                                                                    eax = sub_466060(&decomp_var_38, 0x1);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    esp = esp - 0x18;
                                                                    eax = sub_465900(&arg_0, 0x0);
                                                                    if (*(int16_t *)word_4c6dc4 != *(int16_t *)eax) {
                                                                            eax = sub_466060(&decomp_var_38, 0x1);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            eax = sub_465f60(&arg_18);
                                                                            decomp_var_78 = ecx;
                                                                            decomp_var_78 = arg_14;
                                                                            eax = sub_465f60(&arg_4);
                                                                            esp = esp - 0x3c;
                                                                            eax = sub_40d310(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44);
                                                                            ecx = *(int16_t *)eax & 0xffff;
                                                                            *(int16_t *)esi = ecx;
                                                                    }
                                                                    else {
                                                                            decomp_var_68 = 0x0;
                                                                            esp = esp - 0x8;
                                                                            decomp_var_6c = &arg_0;
                                                                            if (*(int16_t *)word_4c6d94 != *(int16_t *)sub_465900(decomp_var_6c, 0x0)) {
                                                                                    eax = sub_465f60(&arg_18);
                                                                                    decomp_var_78 = ecx;
                                                                                    decomp_var_78 = arg_14;
                                                                                    eax = sub_465f60(&arg_4);
                                                                                    esp = esp - 0x30;
                                                                                    eax = sub_41f5a0(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                    ecx = *(int16_t *)eax & 0xffff;
                                                                                    *(int16_t *)esi = ecx;
                                                                            }
                                                                            else {
                                                                                    esp = esp - 0x8;
                                                                                    eax = sub_465900(&arg_0, 0x0);
                                                                                    ecx = *(int16_t *)word_4c6df8;
                                                                                    if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                                                                                            eax = sub_465f60(&arg_18);
                                                                                            esp = esp - 0x18;
                                                                                            decomp_var_78 = ecx;
                                                                                            decomp_var_78 = arg_14;
                                                                                            edx = &decomp_var_48;
                                                                                            sub_465f60(edx);
                                                                                            esp = esp - 0x18;
                                                                                            ecx = *(int16_t *)sub_426350() & 0xffff;
                                                                                            *(int16_t *)esi = ecx;
                                                                                    }
                                                                                    else {
                                                                                            *(int16_t *)esi = *(int16_t *)word_4c6cf0;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    esp = esp - 0x8;
                                                                    eax = sub_465900(&arg_0, 0x0);
                                                                    if (*(int16_t *)word_4c6e14 != *(int16_t *)eax) {
                                                                            eax = sub_466060(&decomp_var_38, 0x1);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            esp = esp - 0x10;
                                                                            eax = sub_46b050(&decomp_var_38, decomp_var_64, decomp_var_60);
                                                                            if (eax[0x6] >= 0x10) {
                                                                                    eax = eax[0x1];
                                                                            }
                                                                            else {
                                                                                    eax = eax + 0x4;
                                                                            }
                                                                            ebx = 0x4;
                                                                            decomp_var_70 = &decomp_var_54;
                                                                            sub_410c10(decomp_var_70, "message: %s", eax);
                                                                            sub_45bb70();
                                                                            esp = (esp - 0xc) + 0xc - 0x8;
                                                                            eax = sub_465900(&arg_0, 0x0);
                                                                            if (*(int16_t *)word_4c6dc4 != *(int16_t *)eax) {
                                                                                    eax = sub_466060(&decomp_var_38, 0x1);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    eax = sub_465f60(&arg_18);
                                                                                    decomp_var_78 = ecx;
                                                                                    decomp_var_78 = arg_14;
                                                                                    eax = sub_465f60(&arg_4);
                                                                                    esp = esp - 0x3c;
                                                                                    eax = sub_40d310(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44);
                                                                                    ecx = *(int16_t *)eax & 0xffff;
                                                                                    *(int16_t *)esi = ecx;
                                                                            }
                                                                            else {
                                                                                    decomp_var_68 = 0x0;
                                                                                    esp = esp - 0x8;
                                                                                    decomp_var_6c = &arg_0;
                                                                                    if (*(int16_t *)word_4c6d94 != *(int16_t *)sub_465900(decomp_var_6c, 0x0)) {
                                                                                            eax = sub_465f60(&arg_18);
                                                                                            decomp_var_78 = ecx;
                                                                                            decomp_var_78 = arg_14;
                                                                                            eax = sub_465f60(&arg_4);
                                                                                            esp = esp - 0x30;
                                                                                            eax = sub_41f5a0(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74, decomp_var_70, decomp_var_6c, decomp_var_68, decomp_var_64, decomp_var_60, decomp_var_5c, decomp_var_58, decomp_var_54, decomp_var_50, decomp_var_4c);
                                                                                            ecx = *(int16_t *)eax & 0xffff;
                                                                                            *(int16_t *)esi = ecx;
                                                                                    }
                                                                                    else {
                                                                                            esp = esp - 0x8;
                                                                                            eax = sub_465900(&arg_0, 0x0);
                                                                                            if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                                                                                                    eax = sub_465f60(&arg_18);
                                                                                                    decomp_var_78 = ecx;
                                                                                                    decomp_var_78 = arg_14;
                                                                                                    eax = sub_465f60(&arg_4);
                                                                                                    esp = esp - 0x30;
                                                                                                    eax = sub_40d450(&arg_0, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, decomp_var_74);
                                                                                                    ecx = *(int16_t *)eax & 0xffff;
                                                                                                    *(int16_t *)esi = ecx;
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x8;
                                                                                                    eax = sub_465900(&arg_0, 0x0);
                                                                                                    ecx = *(int16_t *)word_4c6d0c;
                                                                                                    if (*(int16_t *)word_4c6d0c != *(int16_t *)eax) {
                                                                                                            eax = sub_465ff0(&arg_4);
                                                                                                            esp = esp - 0xc;
                                                                                                            eax = sub_465900(&arg_0, 0x0);
                                                                                                            ecx = *(int16_t *)word_4c6df8;
                                                                                                            if (*(int16_t *)word_4c6df8 != *(int16_t *)eax) {
                                                                                                                    eax = sub_465f60(&arg_18);
                                                                                                                    esp = esp - 0x18;
                                                                                                                    decomp_var_78 = ecx;
                                                                                                                    decomp_var_78 = arg_14;
                                                                                                                    edx = &decomp_var_48;
                                                                                                                    sub_465f60(edx);
                                                                                                                    esp = esp - 0x18;
                                                                                                                    ecx = *(int16_t *)sub_426350() & 0xffff;
                                                                                                                    *(int16_t *)esi = ecx;
                                                                                                            }
                                                                                                            else {
                                                                                                                    *(int16_t *)esi = *(int16_t *)word_4c6cf0;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            *(int16_t *)esi = *(int16_t *)word_4c6cf0;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = *(int16_t *)word_4c6cf0;
                                                                            *(int16_t *)esi = *(int16_t *)word_4c6cf0;
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            eax = decomp_var_54 - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
            if (ecx <= 0x1) {
                    esp = esp - 0x4;
                    (*(**eax + 0x4))(eax);
            }
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            eax = esi;
            *0x0 = decomp_var_c;
    }
    return eax;
}
