// sub_422a90 @ 0x422a90
// hopper name: sub_422a90
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_422a90() {
    decomp_var_c = *0x0;
    decomp_var_9c = ebx;
    decomp_var_a0 = ebp;
    decomp_var_a4 = esi;
    decomp_var_a8 = edi;
    esp = esp - 0xac;
    decomp_var_ac = *dword_4c8db8 ^ &decomp_var_a8;
    *0x0 = &decomp_var_c;
    esi = ecx;
    sub_465870();
    sub_465870();
    sub_465870();
    decomp_var_74 = 0x0;
    decomp_var_70 = 0x0;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_98 = (*(*eax + 0xc))() + 0x10;
            eax = sub_466060(&decomp_var_2c, 0x1);
            sub_465ff0(eax);
            sub_465fa0();
            decomp_var_8c = sub_465930();
            eax = sub_466060(&decomp_var_2c, 0x1);
            esp = esp - 0x1c;
            eax = sub_465900(&decomp_var_34, 0x0);
            decomp_var_94 = *(int16_t *)eax;
            sub_465fa0();
            eax = decomp_var_94;
            if (*(int16_t *)word_4c6c38 != eax) {
                    if (*(int16_t *)word_4c6c30 != eax) {
                            eax = sub_466060(&decomp_var_2c, 0x0);
                            sub_465ff0(eax);
                            sub_465fa0();
                            eax = sub_465900(&decomp_var_34, 0x2);
                            decomp_var_84 = *(int8_t *)eax & 0xff;
                            esp = esp - 0x1c;
                            eax = sub_402060(&decomp_var_4c, &decomp_var_84, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            edi = *eax;
                            ecx = eax[0x1];
                            eax = esi[0x2];
                            ebp = eax[0x915];
                            eax = eax + 0x2450;
                            decomp_var_74 = edi;
                            decomp_var_70 = ecx;
                            if (edi == 0x0 || edi != eax) {
                                    sub_47a948();
                            }
                            if (decomp_var_70 == ebp) {
                                    eax = decomp_var_98 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                    if (ecx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = 0xfffe795f;
                                    *0x0 = decomp_var_c;
                            }
                            else {
                                    eax = sub_465900(&decomp_var_34, 0x1);
                                    ebp = *(int16_t *)eax;
                                    decomp_var_b0 = ecx;
                                    decomp_var_84 = &decomp_var_b0;
                                    decomp_var_b0 = ebp;
                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                    esp = esp - 0x1c;
                                    eax = sub_45fc30(&decomp_var_4c, eax, decomp_var_b0);
                                    decomp_var_7c = *eax;
                                    decomp_var_78 = eax[0x1];
                                    sub_465fa0();
                                    if (edi == 0x0) {
                                            sub_47a948();
                                    }
                                    if (decomp_var_70 == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    if (decomp_var_78 == decomp_var_70[0xa]) {
                                            if (*(sub_410b70() + 0x4) == decomp_var_7c) {
                                                    esp = esp - 0x8;
                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                    decomp_var_34 = *(int8_t *)eax;
                                                    if (*(sub_410b70() + 0xc) != (decomp_var_34 & 0xff)) {
                                                            sub_40b8b0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = 0xfffe795b;
                                                            *0x0 = decomp_var_c;
                                                    }
                                                    else {
                                                            esp = esp - 0x8;
                                                            decomp_var_48 = *dword_bb7140;
                                                            eax = sub_401ff0(&decomp_var_34, &decomp_var_7c, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                            decomp_var_84 = eax;
                                                            eax = *eax;
                                                            if (eax == 0x0 || eax != 0xbb713c) {
                                                                    sub_47a948();
                                                            }
                                                            edx = decomp_var_48;
                                                            if (decomp_var_84[0x1] != edx) {
                                                                    eax = decomp_var_98 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    if (edx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = 0xfffeb3f7;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                            else {
                                                                    eax = decomp_var_94;
                                                                    if (*(int16_t *)word_4c6c18 != eax) {
                                                                            if (*(int16_t *)word_4c6c1c == eax) {
                                                                                    decomp_var_b0 = 0xbb713c;
                                                                                    decomp_var_b0 = ebp;
                                                                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                                                                    decomp_var_b4 = eax;
                                                                                    eax = sub_45fc30(&decomp_var_4c, decomp_var_b4, decomp_var_b0);
                                                                                    ebp = *eax;
                                                                                    sub_465fa0();
                                                                                    esp = esp - 0x1c;
                                                                                    decomp_var_b4 = ebp;
                                                                                    if (edi == 0x0) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    ebx = decomp_var_70;
                                                                                    if (ebx == edi[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_b8 = ebx + 0x10;
                                                                                    if (sub_460b30(decomp_var_b8, decomp_var_b4) == 0x0) {
                                                                                            sub_40b8b0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0xfffe7956;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                            esp = esp - 0x8;
                                                                                            decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                            eax = sub_465f60(&arg_14);
                                                                                            decomp_var_c8 = ecx;
                                                                                            decomp_var_8c = &decomp_var_c8;
                                                                                            eax = &decomp_var_c8;
                                                                                            esp = esp - 0x1c;
                                                                                            decomp_var_cc = ebp;
                                                                                            *(int16_t *)eax = arg_10;
                                                                                            ecx = esi;
                                                                                            esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                            if (esi != 0x0) {
                                                                                                    sub_40b8b0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = esi;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                            else {
                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                    if (ecx <= 0x1) {
                                                                                                            esp = esp - 0x4;
                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                    }
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0x0;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(int16_t *)word_4c6c20 == eax) {
                                                                                            ebx = 0x5;
                                                                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            eax = sub_465900(&decomp_var_84, 0x2);
                                                                                            decomp_var_84 = *(int8_t *)eax & 0xff;
                                                                                            eax = sub_402060(&decomp_var_4c, &decomp_var_84, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                                                            decomp_var_94 = *eax;
                                                                                            decomp_var_90 = eax[0x1];
                                                                                            esp = esp - 0x20;
                                                                                            decomp_var_7c = esi[0x2] + 0x2450;
                                                                                            eax = sub_40dfe0(&decomp_var_7c);
                                                                                            if (eax != 0x0) {
                                                                                                    sub_40b8b0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0xfffe794c;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                            else {
                                                                                                    eax = sub_465900(&decomp_var_84, 0x1);
                                                                                                    decomp_var_b0 = ecx;
                                                                                                    decomp_var_84 = &decomp_var_b0;
                                                                                                    decomp_var_b0 = *(int16_t *)eax;
                                                                                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                                                                                    esp = esp - 0x1c;
                                                                                                    eax = sub_45fc30(&decomp_var_4c, eax, decomp_var_b0);
                                                                                                    ebp = *eax;
                                                                                                    edi = eax[0x1];
                                                                                                    decomp_var_7c = ebp;
                                                                                                    sub_465fa0();
                                                                                                    if (edi == *(int16_t *)(sub_410b70() + 0x8)) {
                                                                                                            if (*(sub_410b70() + 0x4) == ebp) {
                                                                                                                    esp = esp - 0x8;
                                                                                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                                                                                    if (*(sub_410b70() + 0xc) != (*(int8_t *)eax & 0xff)) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0xfffe7947;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            decomp_var_80 = *dword_bb7140;
                                                                                                                            esp = esp - 0xc;
                                                                                                                            decomp_var_b8 = &decomp_var_4c;
                                                                                                                            decomp_var_84 = 0xbb713c;
                                                                                                                            eax = sub_401ff0(decomp_var_b8, &decomp_var_7c, &decomp_var_84, decomp_var_ac, decomp_var_a8);
                                                                                                                            if (sub_401050(decomp_var_b0) != 0x0) {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = 0xfffeb3ee;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    if (decomp_var_8c == ebx) {
                                                                                                                                            sub_466060(&decomp_var_2c, 0x4);
                                                                                                                                            eax = sub_465900(&decomp_var_84, 0x0);
                                                                                                                                            edi = *(int8_t *)eax & 0xff;
                                                                                                                                            sub_465fa0();
                                                                                                                                            esp = esp - 0x18;
                                                                                                                                            if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                                                    if (*(int16_t *)word_4c6c08 == *(int16_t *)(sub_410b70() + 0x10)) {
                                                                                                                                                            esp = esp - 0xc;
                                                                                                                                                            decomp_var_b8 = sub_410b70() + 0x4;
                                                                                                                                                            if (sub_4619f0(decomp_var_b8, decomp_var_b4, decomp_var_b0) != 0x1) {
                                                                                                                                                                    sub_40b8b0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    eax = 0xfffe7942;
                                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    esp = esp - 0x8;
                                                                                                                                                                    if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                                                                            sub_40b8b0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            eax = 0xfffe793f;
                                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                                                                            ebp = arg_10;
                                                                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                                                                            esp = esp - 0x24;
                                                                                                                                                                            decomp_var_c8 = ebp;
                                                                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                                            ebx = eax;
                                                                                                                                                                            if (ebx != 0x0) {
                                                                                                                                                                                    sub_40b8b0();
                                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                                    eax = ebx;
                                                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                                            }
                                                                                                                                                                            else {
                                                                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                                                                                    esp = esp - 0x24;
                                                                                                                                                                                    ecx = esi;
                                                                                                                                                                                    decomp_var_c8 = ebp;
                                                                                                                                                                                    eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                                                    esi = eax;
                                                                                                                                                                                    if (esi != 0x0) {
                                                                                                                                                                                            sub_40b8b0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            eax = esi;
                                                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                                                    }
                                                                                                                                                                                    else {
                                                                                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                                                                                            }
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                                            eax = 0x0;
                                                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                                                    }
                                                                                                                                                                            }
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            sub_40b8b0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = 0xfffe7942;
                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    esp = esp - 0x8;
                                                                                                                                                    if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                                                            sub_40b8b0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = 0xfffe793f;
                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                                                            ebp = arg_10;
                                                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                                                            esp = esp - 0x24;
                                                                                                                                                            decomp_var_c8 = ebp;
                                                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                            ebx = eax;
                                                                                                                                                            if (ebx != 0x0) {
                                                                                                                                                                    sub_40b8b0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    eax = ebx;
                                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                                                                    esp = esp - 0x24;
                                                                                                                                                                    ecx = esi;
                                                                                                                                                                    decomp_var_c8 = ebp;
                                                                                                                                                                    eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                                    esi = eax;
                                                                                                                                                                    if (esi != 0x0) {
                                                                                                                                                                            sub_40b8b0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            eax = esi;
                                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                                    }
                                                                                                                                                                    else {
                                                                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                                                                            }
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            sub_465fa0();
                                                                                                                                                                            eax = 0x0;
                                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                                    }
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            esp = esp - 0x8;
                                                                                                                                            if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = 0xfffe793d;
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                                                                    esp = esp - 0x8;
                                                                                                                                                    decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                                                    decomp_var_8c = &decomp_var_c8;
                                                                                                                                                    eax = &decomp_var_c8;
                                                                                                                                                    esp = esp - 0x1c;
                                                                                                                                                    decomp_var_cc = ebp;
                                                                                                                                                    *(int16_t *)eax = arg_10;
                                                                                                                                                    ecx = esi;
                                                                                                                                                    esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                    if (esi != 0x0) {
                                                                                                                                                            sub_40b8b0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = esi;
                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                                                            }
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = 0x0;
                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe7947;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe7947;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int16_t *)word_4c6c10 == eax) {
                                                                                                    esi[0xa84] = eax | 0xffffffff;
                                                                                                    esi[0xa85] = eax | 0xffffffff;
                                                                                                    esi[0xa86] = eax | 0xffffffff;
                                                                                                    sub_466060(&decomp_var_2c, 0x4);
                                                                                                    edi = sub_465930();
                                                                                                    decomp_var_94 = edi;
                                                                                                    sub_465fa0();
                                                                                                    decomp_var_b0 = ecx;
                                                                                                    decomp_var_b0 = ebp;
                                                                                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                                                                                    esp = esp - 0x1c;
                                                                                                    decomp_var_b8 = &decomp_var_4c;
                                                                                                    ebp = *sub_45fc30(decomp_var_b8, eax, decomp_var_b0);
                                                                                                    decomp_var_7c = ebp;
                                                                                                    sub_465fa0();
                                                                                                    if (edi != 0x0) {
                                                                                                            if (edi <= 0x3) {
                                                                                                                    if (*(sub_410b70() + 0x4) != ebp) {
                                                                                                                            if (*(int8_t *)(esi[0x2] + (ebp + ebp * 0x8) * 0x4 + 0x4) != 0x0) {
                                                                                                                                    ebp = 0x0;
                                                                                                                                    decomp_var_34 = *(sub_410b70() + 0x4);
                                                                                                                                    if (edi > 0x0) {
                                                                                                                                            edi = esi + 0x2a10;
                                                                                                                                            while (true) {
                                                                                                                                                    eax = sub_466060(&decomp_var_1c, 0x4);
                                                                                                                                                    eax = sub_465900(&decomp_var_84, ebp);
                                                                                                                                                    *edi = *(int8_t *)eax & 0xff;
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = sub_402060(&decomp_var_2c, edi, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                                                                                                                    decomp_var_8c = *eax;
                                                                                                                                                    decomp_var_88 = eax[0x1];
                                                                                                                                                    esp = esp - 0x1c;
                                                                                                                                                    decomp_var_4c = esi[0x2] + 0x2450;
                                                                                                                                                    eax = sub_40dfe0(&decomp_var_4c);
                                                                                                                                                    if (eax != 0x0) {
                                                                                                                                                            temp_0 = 0x3;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    eax = *edi;
                                                                                                                                                    eax = eax + eax * 0x8;
                                                                                                                                                    if (*(int8_t *)(esi[0x2] + eax * 0x4 + 0x4) == 0x1) {
                                                                                                                                                            temp_0 = 0x1;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    eax = sub_410b70();
                                                                                                                                                    esp = esp - 0x8;
                                                                                                                                                    eax = sub_460a10(eax + 0x4, decomp_var_b0);
                                                                                                                                                    if (eax == 0x0) {
                                                                                                                                                            temp_0 = 0x1;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    ebp = &arg_fffffffffffffffd;
                                                                                                                                                    if (ebp != decomp_var_94) {
                                                                                                                                                            eax = sub_410b70();
                                                                                                                                                            decomp_var_34 = eax[0x1];
                                                                                                                                                            edi = edi + 0x4;
                                                                                                                                                            if (ebp < decomp_var_94) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            temp_0 = 0x2;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    eax = sub_410b70();
                                                                                                                                                    esp = esp - 0x8;
                                                                                                                                                    eax = sub_460a10(eax + 0x4, decomp_var_b0);
                                                                                                                                                    if (eax != 0x0) {
                                                                                                                                                            edi = edi + 0x4;
                                                                                                                                                            if (ebp < decomp_var_94) {
                                                                                                                                                                    continue;
                                                                                                                                                            }
                                                                                                                                                            temp_0 = 0x2;
                                                                                                                                                            break;
                                                                                                                                                    }
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = 0xfffe792e;
                                                                                                                                                    temp_0 = 0x0;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            switch (temp_0) {
                                                                                                                                                case 0:
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                    break;
                                                                                                                                                case 1:
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = 0xfffe7933;
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                    break;
                                                                                                                                                case 2:
                                                                                                                                                    decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                                                                    decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                                                    decomp_var_8c = &decomp_var_c8;
                                                                                                                                                    eax = &decomp_var_c8;
                                                                                                                                                    esp = esp - 0x24;
                                                                                                                                                    decomp_var_cc = decomp_var_7c;
                                                                                                                                                    *(int16_t *)eax = arg_10;
                                                                                                                                                    ecx = esi;
                                                                                                                                                    esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                    if (esi != 0x0) {
                                                                                                                                                            sub_40b8b0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = esi;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                                                            }
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = 0x0;
                                                                                                                                                    }
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                    break;
                                                                                                                                                default:
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = 0xfffe7933;
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                                                            decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                                            decomp_var_8c = &decomp_var_c8;
                                                                                                                                            eax = &decomp_var_c8;
                                                                                                                                            esp = esp - 0x24;
                                                                                                                                            decomp_var_cc = decomp_var_7c;
                                                                                                                                            *(int16_t *)eax = arg_10;
                                                                                                                                            ecx = esi;
                                                                                                                                            esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                            if (esi != 0x0) {
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = esi;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                    if (ecx <= 0x1) {
                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                                                    }
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = 0x0;
                                                                                                                                            }
                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = 0xfffe7938;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0xfffe7938;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe7938;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe7938;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (*(int16_t *)word_4c6c14 == eax) {
                                                                                                            eax = sub_466060(&decomp_var_1c, 0x2);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_465900(&decomp_var_84, 0x2);
                                                                                                            edx = *(int8_t *)eax & 0xff;
                                                                                                            decomp_var_84 = edx;
                                                                                                            eax = sub_402060(&decomp_var_2c, &decomp_var_84, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                                                                            edx = *eax;
                                                                                                            decomp_var_90 = eax[0x1];
                                                                                                            decomp_var_94 = edx;
                                                                                                            esp = esp - 0x20;
                                                                                                            decomp_var_4c = esi[0x2] + 0x2450;
                                                                                                            eax = sub_40dfe0(&decomp_var_4c);
                                                                                                            if (eax != 0x0) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe7929;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                            else {
                                                                                                                    sub_466060(&decomp_var_1c, 0x1);
                                                                                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                                                                                    edi = *(int16_t *)eax;
                                                                                                                    sub_465fa0();
                                                                                                                    decomp_var_b0 = ecx;
                                                                                                                    decomp_var_b0 = edi;
                                                                                                                    eax = sub_466060(&decomp_var_1c, 0x2);
                                                                                                                    esp = esp - 0x24;
                                                                                                                    eax = sub_45fc30(&decomp_var_2c, eax, decomp_var_b0);
                                                                                                                    ecx = *eax;
                                                                                                                    ebp = eax[0x1];
                                                                                                                    decomp_var_7c = ecx;
                                                                                                                    sub_465fa0();
                                                                                                                    if (ebp == *(int16_t *)(sub_410b70() + 0x8)) {
                                                                                                                            if (*(sub_410b70() + 0x4) == decomp_var_7c) {
                                                                                                                                    esp = esp - 0x8;
                                                                                                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                                                                                                    if (*(sub_410b70() + 0xc) == (*(int8_t *)eax & 0xff)) {
                                                                                                                                            if (*(int16_t *)word_4c6c08 != *(int16_t *)(sub_410b70() + 0x8)) {
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = 0xfffe7924;
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    decomp_var_b0 = *(int16_t *)word_4c6c08;
                                                                                                                                                    decomp_var_b0 = edi;
                                                                                                                                                    eax = sub_466060(&decomp_var_1c, 0x4);
                                                                                                                                                    eax = sub_45fc30(&decomp_var_2c, eax, decomp_var_b0);
                                                                                                                                                    edi = *eax;
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    esp = esp - 0x20;
                                                                                                                                                    decomp_var_b8 = sub_410b70() + 0x4;
                                                                                                                                                    if (sub_4619f0(decomp_var_b8, decomp_var_b4, decomp_var_b0) == 0x0) {
                                                                                                                                                            sub_40b8b0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = 0xfffe791f;
                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                                                            decomp_var_c8 = arg_10;
                                                                                                                                                            esp = esp - 0x24;
                                                                                                                                                            ecx = esi;
                                                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                            esi = eax;
                                                                                                                                                            if (esi != 0x0) {
                                                                                                                                                                    sub_40b8b0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    eax = esi;
                                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                            }
                                                                                                                                                            else {
                                                                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                                    if (ecx <= 0x1) {
                                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                                                                    }
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    sub_465fa0();
                                                                                                                                                                    eax = 0x0;
                                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                                            }
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            sub_40b8b0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            eax = 0xfffe7924;
                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = 0xfffe7924;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0xfffe7924;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffea06f;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = decomp_var_98 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], 0xffffffff);
                                                                            if (ecx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0x0;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    sub_40b8b0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = 0xfffe795b;
                                                    *0x0 = decomp_var_c;
                                            }
                                    }
                                    else {
                                            sub_40b8b0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = 0xfffe795b;
                                            *0x0 = decomp_var_c;
                                    }
                            }
                    }
                    else {
                            esp = esp - 0x8;
                            decomp_var_48 = *dword_bb7140;
                            eax = sub_401ff0(&decomp_var_34, &decomp_var_7c, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                            decomp_var_84 = eax;
                            eax = *eax;
                            if (eax == 0x0 || eax != 0xbb713c) {
                                    sub_47a948();
                            }
                            edx = decomp_var_48;
                            if (decomp_var_84[0x1] != edx) {
                                    eax = decomp_var_98 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = 0xfffeb3f7;
                                    *0x0 = decomp_var_c;
                            }
                            else {
                                    eax = decomp_var_94;
                                    if (*(int16_t *)word_4c6c18 != eax) {
                                            if (*(int16_t *)word_4c6c1c == eax) {
                                                    decomp_var_b0 = 0xbb713c;
                                                    decomp_var_b0 = 0x0;
                                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                                    decomp_var_b4 = eax;
                                                    eax = sub_45fc30(&decomp_var_4c, decomp_var_b4, decomp_var_b0);
                                                    ebp = *eax;
                                                    sub_465fa0();
                                                    esp = esp - 0x1c;
                                                    decomp_var_b4 = ebp;
                                                    if (0x0 == 0x0) {
                                                            sub_47a948();
                                                    }
                                                    ebx = decomp_var_70;
                                                    if (ebx == *0x4) {
                                                            sub_47a948();
                                                    }
                                                    esp = esp - 0x4;
                                                    decomp_var_b8 = ebx + 0x10;
                                                    if (sub_460b30(decomp_var_b8, decomp_var_b4) == 0x0) {
                                                            sub_40b8b0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = 0xfffe7956;
                                                            *0x0 = decomp_var_c;
                                                    }
                                                    else {
                                                            decomp_var_b0 = *(sub_410b70() + 0xc);
                                                            esp = esp - 0x8;
                                                            decomp_var_b4 = *(sub_410b70() + 0xc);
                                                            eax = sub_465f60(&arg_14);
                                                            decomp_var_c8 = ecx;
                                                            decomp_var_8c = &decomp_var_c8;
                                                            eax = &decomp_var_c8;
                                                            esp = esp - 0x1c;
                                                            decomp_var_cc = ebp;
                                                            *(int16_t *)eax = arg_10;
                                                            ecx = esi;
                                                            esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                            if (esi != 0x0) {
                                                                    sub_40b8b0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = esi;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                            else {
                                                                    eax = decomp_var_98 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                    if (ecx <= 0x1) {
                                                                            esp = esp - 0x4;
                                                                            (*(**eax + 0x4))(eax);
                                                                    }
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = 0x0;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c6c20 == eax) {
                                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            eax = sub_465900(&decomp_var_84, 0x2);
                                                            decomp_var_84 = *(int8_t *)eax & 0xff;
                                                            eax = sub_402060(&decomp_var_4c, &decomp_var_84, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                            decomp_var_94 = *eax;
                                                            decomp_var_90 = eax[0x1];
                                                            esp = esp - 0x20;
                                                            decomp_var_7c = esi[0x2] + 0x2450;
                                                            eax = sub_40dfe0(&decomp_var_7c);
                                                            if (eax != 0x0) {
                                                                    sub_40b8b0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = 0xfffe794c;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                            else {
                                                                    ebx = 0x5;
                                                                    eax = sub_465900(&decomp_var_84, 0x1);
                                                                    decomp_var_b0 = ecx;
                                                                    decomp_var_84 = &decomp_var_b0;
                                                                    decomp_var_b0 = *(int16_t *)eax;
                                                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                                                    esp = esp - 0x1c;
                                                                    eax = sub_45fc30(&decomp_var_4c, eax, decomp_var_b0);
                                                                    ebp = *eax;
                                                                    edi = eax[0x1];
                                                                    decomp_var_7c = ebp;
                                                                    sub_465fa0();
                                                                    if (edi == *(int16_t *)(sub_410b70() + 0x8)) {
                                                                            if (*(sub_410b70() + 0x4) == ebp) {
                                                                                    esp = esp - 0x8;
                                                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                                                    if (*(sub_410b70() + 0xc) != (*(int8_t *)eax & 0xff)) {
                                                                                            sub_40b8b0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0xfffe7947;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                                    else {
                                                                                            decomp_var_80 = *dword_bb7140;
                                                                                            esp = esp - 0xc;
                                                                                            decomp_var_b8 = &decomp_var_4c;
                                                                                            decomp_var_84 = 0xbb713c;
                                                                                            eax = sub_401ff0(decomp_var_b8, &decomp_var_7c, &decomp_var_84, decomp_var_ac, decomp_var_a8);
                                                                                            if (sub_401050(decomp_var_b0) != 0x0) {
                                                                                                    sub_40b8b0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0xfffeb3ee;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                            else {
                                                                                                    if (decomp_var_8c == ebx) {
                                                                                                            sub_466060(&decomp_var_2c, 0x4);
                                                                                                            eax = sub_465900(&decomp_var_84, 0x0);
                                                                                                            edi = *(int8_t *)eax & 0xff;
                                                                                                            sub_465fa0();
                                                                                                            esp = esp - 0x18;
                                                                                                            if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                    if (*(int16_t *)word_4c6c08 == *(int16_t *)(sub_410b70() + 0x10)) {
                                                                                                                            esp = esp - 0xc;
                                                                                                                            decomp_var_b8 = sub_410b70() + 0x4;
                                                                                                                            if (sub_4619f0(decomp_var_b8, decomp_var_b4, decomp_var_b0) != 0x1) {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = 0xfffe7942;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    esp = esp - 0x8;
                                                                                                                                    if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                                            sub_40b8b0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            eax = 0xfffe793f;
                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                                            ebp = arg_10;
                                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                                            esp = esp - 0x24;
                                                                                                                                            decomp_var_c8 = ebp;
                                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                            ebx = eax;
                                                                                                                                            if (ebx != 0x0) {
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = ebx;
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                                                    esp = esp - 0x24;
                                                                                                                                                    ecx = esi;
                                                                                                                                                    decomp_var_c8 = ebp;
                                                                                                                                                    eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                                    esi = eax;
                                                                                                                                                    if (esi != 0x0) {
                                                                                                                                                            sub_40b8b0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = esi;
                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                    }
                                                                                                                                                    else {
                                                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                                                            }
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            sub_465fa0();
                                                                                                                                                            eax = 0x0;
                                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0xfffe7942;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    esp = esp - 0x8;
                                                                                                                    if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0xfffe793f;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                            ebp = arg_10;
                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                            esp = esp - 0x24;
                                                                                                                            decomp_var_c8 = ebp;
                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                            ebx = eax;
                                                                                                                            if (ebx != 0x0) {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = ebx;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                                    esp = esp - 0x24;
                                                                                                                                    ecx = esi;
                                                                                                                                    decomp_var_c8 = ebp;
                                                                                                                                    eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                    esi = eax;
                                                                                                                                    if (esi != 0x0) {
                                                                                                                                            sub_40b8b0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            eax = esi;
                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                                    esp = esp - 0x4;
                                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                                            }
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            eax = 0x0;
                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x8;
                                                                                                            if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe793d;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                            else {
                                                                                                                    decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                                    esp = esp - 0x8;
                                                                                                                    decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                    decomp_var_8c = &decomp_var_c8;
                                                                                                                    eax = &decomp_var_c8;
                                                                                                                    esp = esp - 0x1c;
                                                                                                                    decomp_var_cc = ebp;
                                                                                                                    *(int16_t *)eax = arg_10;
                                                                                                                    ecx = esi;
                                                                                                                    esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                    if (esi != 0x0) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = esi;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                            }
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0x0;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_40b8b0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0xfffe7947;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_40b8b0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0xfffe7947;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (*(int16_t *)word_4c6c10 == eax) {
                                                                    esi[0xa84] = eax | 0xffffffff;
                                                                    esi[0xa85] = eax | 0xffffffff;
                                                                    esi[0xa86] = eax | 0xffffffff;
                                                                    sub_466060(&decomp_var_2c, 0x4);
                                                                    edi = sub_465930();
                                                                    decomp_var_94 = edi;
                                                                    sub_465fa0();
                                                                    decomp_var_b0 = ecx;
                                                                    decomp_var_b0 = 0x0;
                                                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                                                    esp = esp - 0x1c;
                                                                    decomp_var_b8 = &decomp_var_4c;
                                                                    ebp = *sub_45fc30(decomp_var_b8, eax, decomp_var_b0);
                                                                    decomp_var_7c = ebp;
                                                                    sub_465fa0();
                                                                    if (edi != 0x0) {
                                                                            if (edi <= 0x3) {
                                                                                    if (*(sub_410b70() + 0x4) != ebp) {
                                                                                            if (*(int8_t *)(esi[0x2] + (ebp + ebp * 0x8) * 0x4 + 0x4) != 0x0) {
                                                                                                    ebp = 0x0;
                                                                                                    decomp_var_34 = *(sub_410b70() + 0x4);
                                                                                                    if (edi > 0x0) {
                                                                                                            edi = esi + 0x2a10;
                                                                                                            while (true) {
                                                                                                                    eax = sub_466060(&decomp_var_1c, 0x4);
                                                                                                                    eax = sub_465900(&decomp_var_84, ebp);
                                                                                                                    *edi = *(int8_t *)eax & 0xff;
                                                                                                                    sub_465fa0();
                                                                                                                    eax = sub_402060(&decomp_var_2c, edi, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                                                                                    decomp_var_8c = *eax;
                                                                                                                    decomp_var_88 = eax[0x1];
                                                                                                                    esp = esp - 0x1c;
                                                                                                                    decomp_var_4c = esi[0x2] + 0x2450;
                                                                                                                    eax = sub_40dfe0(&decomp_var_4c);
                                                                                                                    if (eax != 0x0) {
                                                                                                                            temp_0 = 0x3;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    eax = *edi;
                                                                                                                    eax = eax + eax * 0x8;
                                                                                                                    if (*(int8_t *)(esi[0x2] + eax * 0x4 + 0x4) == 0x1) {
                                                                                                                            temp_0 = 0x1;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    eax = sub_410b70();
                                                                                                                    esp = esp - 0x8;
                                                                                                                    eax = sub_460a10(eax + 0x4, decomp_var_b0);
                                                                                                                    if (eax == 0x0) {
                                                                                                                            temp_0 = 0x1;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    ebp = &arg_fffffffffffffffd;
                                                                                                                    if (ebp != decomp_var_94) {
                                                                                                                            eax = sub_410b70();
                                                                                                                            decomp_var_34 = eax[0x1];
                                                                                                                            edi = edi + 0x4;
                                                                                                                            if (ebp < decomp_var_94) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_0 = 0x2;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    eax = sub_410b70();
                                                                                                                    esp = esp - 0x8;
                                                                                                                    eax = sub_460a10(eax + 0x4, decomp_var_b0);
                                                                                                                    if (eax != 0x0) {
                                                                                                                            edi = edi + 0x4;
                                                                                                                            if (ebp < decomp_var_94) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_0 = 0x2;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe792e;
                                                                                                                    temp_0 = 0x0;
                                                                                                                    break;
                                                                                                            }
                                                                                                            switch (temp_0) {
                                                                                                                case 0:
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                    break;
                                                                                                                case 1:
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe7933;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                    break;
                                                                                                                case 2:
                                                                                                                    decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                                    decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                    decomp_var_8c = &decomp_var_c8;
                                                                                                                    eax = &decomp_var_c8;
                                                                                                                    esp = esp - 0x24;
                                                                                                                    decomp_var_cc = decomp_var_7c;
                                                                                                                    *(int16_t *)eax = arg_10;
                                                                                                                    ecx = esi;
                                                                                                                    esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                    if (esi != 0x0) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = esi;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                            }
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0x0;
                                                                                                                    }
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                    break;
                                                                                                                default:
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe7933;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                            decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                            decomp_var_c8 = ecx;
                                                                                                            decomp_var_8c = &decomp_var_c8;
                                                                                                            eax = &decomp_var_c8;
                                                                                                            esp = esp - 0x24;
                                                                                                            decomp_var_cc = decomp_var_7c;
                                                                                                            *(int16_t *)eax = arg_10;
                                                                                                            ecx = esi;
                                                                                                            esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                            if (esi != 0x0) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = esi;
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                    if (ecx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                    }
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0x0;
                                                                                                            }
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    sub_40b8b0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0xfffe7938;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            sub_40b8b0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0xfffe7938;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_40b8b0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0xfffe7938;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_40b8b0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0xfffe7938;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                            else {
                                                                    if (*(int16_t *)word_4c6c14 == eax) {
                                                                            eax = sub_466060(&decomp_var_1c, 0x2);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            eax = sub_465900(&decomp_var_84, 0x2);
                                                                            edx = *(int8_t *)eax & 0xff;
                                                                            decomp_var_84 = edx;
                                                                            eax = sub_402060(&decomp_var_2c, &decomp_var_84, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                                            edx = *eax;
                                                                            decomp_var_90 = eax[0x1];
                                                                            decomp_var_94 = edx;
                                                                            esp = esp - 0x20;
                                                                            decomp_var_4c = esi[0x2] + 0x2450;
                                                                            eax = sub_40dfe0(&decomp_var_4c);
                                                                            if (eax != 0x0) {
                                                                                    sub_40b8b0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0xfffe7929;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                            else {
                                                                                    sub_466060(&decomp_var_1c, 0x1);
                                                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                                                    edi = *(int16_t *)eax;
                                                                                    sub_465fa0();
                                                                                    decomp_var_b0 = ecx;
                                                                                    decomp_var_b0 = edi;
                                                                                    eax = sub_466060(&decomp_var_1c, 0x2);
                                                                                    esp = esp - 0x24;
                                                                                    eax = sub_45fc30(&decomp_var_2c, eax, decomp_var_b0);
                                                                                    ecx = *eax;
                                                                                    ebp = eax[0x1];
                                                                                    decomp_var_7c = ecx;
                                                                                    sub_465fa0();
                                                                                    if (ebp == *(int16_t *)(sub_410b70() + 0x8)) {
                                                                                            if (*(sub_410b70() + 0x4) == decomp_var_7c) {
                                                                                                    esp = esp - 0x8;
                                                                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                                                                    if (*(sub_410b70() + 0xc) == (*(int8_t *)eax & 0xff)) {
                                                                                                            if (*(int16_t *)word_4c6c08 != *(int16_t *)(sub_410b70() + 0x8)) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe7924;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                            else {
                                                                                                                    decomp_var_b0 = *(int16_t *)word_4c6c08;
                                                                                                                    decomp_var_b0 = edi;
                                                                                                                    eax = sub_466060(&decomp_var_1c, 0x4);
                                                                                                                    eax = sub_45fc30(&decomp_var_2c, eax, decomp_var_b0);
                                                                                                                    edi = *eax;
                                                                                                                    sub_465fa0();
                                                                                                                    esp = esp - 0x20;
                                                                                                                    decomp_var_b8 = sub_410b70() + 0x4;
                                                                                                                    if (sub_4619f0(decomp_var_b8, decomp_var_b4, decomp_var_b0) == 0x0) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0xfffe791f;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                            decomp_var_c8 = arg_10;
                                                                                                                            esp = esp - 0x24;
                                                                                                                            ecx = esi;
                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                            esi = eax;
                                                                                                                            if (esi != 0x0) {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = esi;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                    if (ecx <= 0x1) {
                                                                                                                                            esp = esp - 0x4;
                                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                                    }
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = 0x0;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe7924;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    sub_40b8b0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0xfffe7924;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            sub_40b8b0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0xfffe7924;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_40b8b0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0xfffea06f;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            eax = decomp_var_98 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], 0xffffffff);
                                            if (ecx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    (*(**eax + 0x4))(eax);
                                            }
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = 0x0;
                                            *0x0 = decomp_var_c;
                                    }
                            }
                    }
            }
            else {
                    esp = esp - 0x8;
                    decomp_var_48 = *dword_bb7140;
                    eax = sub_401ff0(&decomp_var_34, &decomp_var_7c, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                    decomp_var_84 = eax;
                    eax = *eax;
                    if (eax == 0x0 || eax != 0xbb713c) {
                            sub_47a948();
                    }
                    edx = decomp_var_48;
                    if (decomp_var_84[0x1] != edx) {
                            eax = decomp_var_98 - 0x10;
                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                            if (edx <= 0x1) {
                                    esp = esp - 0x4;
                                    (*(**eax + 0x4))(eax);
                            }
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            sub_465fa0();
                            eax = 0xfffeb3f7;
                            *0x0 = decomp_var_c;
                    }
                    else {
                            eax = decomp_var_94;
                            if (*(int16_t *)word_4c6c18 != eax) {
                                    if (*(int16_t *)word_4c6c1c == eax) {
                                            decomp_var_b0 = 0xbb713c;
                                            decomp_var_b0 = 0x0;
                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                            decomp_var_b4 = eax;
                                            eax = sub_45fc30(&decomp_var_4c, decomp_var_b4, decomp_var_b0);
                                            ebp = *eax;
                                            sub_465fa0();
                                            esp = esp - 0x1c;
                                            decomp_var_b4 = ebp;
                                            if (0x0 == 0x0) {
                                                    sub_47a948();
                                            }
                                            ebx = decomp_var_70;
                                            if (ebx == *0x4) {
                                                    sub_47a948();
                                            }
                                            esp = esp - 0x4;
                                            decomp_var_b8 = ebx + 0x10;
                                            if (sub_460b30(decomp_var_b8, decomp_var_b4) == 0x0) {
                                                    sub_40b8b0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = 0xfffe7956;
                                                    *0x0 = decomp_var_c;
                                            }
                                            else {
                                                    decomp_var_b0 = *(sub_410b70() + 0xc);
                                                    esp = esp - 0x8;
                                                    decomp_var_b4 = *(sub_410b70() + 0xc);
                                                    eax = sub_465f60(&arg_14);
                                                    decomp_var_c8 = ecx;
                                                    decomp_var_8c = &decomp_var_c8;
                                                    eax = &decomp_var_c8;
                                                    esp = esp - 0x1c;
                                                    decomp_var_cc = ebp;
                                                    *(int16_t *)eax = arg_10;
                                                    ecx = esi;
                                                    esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                    if (esi != 0x0) {
                                                            sub_40b8b0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = esi;
                                                            *0x0 = decomp_var_c;
                                                    }
                                                    else {
                                                            eax = decomp_var_98 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                            if (ecx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = 0x0;
                                                            *0x0 = decomp_var_c;
                                                    }
                                            }
                                    }
                                    else {
                                            if (*(int16_t *)word_4c6c20 == eax) {
                                                    eax = sub_466060(&decomp_var_2c, 0x2);
                                                    sub_465ff0(eax);
                                                    sub_465fa0();
                                                    eax = sub_465900(&decomp_var_84, 0x2);
                                                    decomp_var_84 = *(int8_t *)eax & 0xff;
                                                    eax = sub_402060(&decomp_var_4c, &decomp_var_84, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                    decomp_var_94 = *eax;
                                                    decomp_var_90 = eax[0x1];
                                                    esp = esp - 0x20;
                                                    decomp_var_7c = esi[0x2] + 0x2450;
                                                    eax = sub_40dfe0(&decomp_var_7c);
                                                    if (eax != 0x0) {
                                                            sub_40b8b0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = 0xfffe794c;
                                                            *0x0 = decomp_var_c;
                                                    }
                                                    else {
                                                            ebx = 0x5;
                                                            eax = sub_465900(&decomp_var_84, 0x1);
                                                            decomp_var_b0 = ecx;
                                                            decomp_var_84 = &decomp_var_b0;
                                                            decomp_var_b0 = *(int16_t *)eax;
                                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                                            esp = esp - 0x1c;
                                                            eax = sub_45fc30(&decomp_var_4c, eax, decomp_var_b0);
                                                            ebp = *eax;
                                                            edi = eax[0x1];
                                                            decomp_var_7c = ebp;
                                                            sub_465fa0();
                                                            if (edi == *(int16_t *)(sub_410b70() + 0x8)) {
                                                                    if (*(sub_410b70() + 0x4) == ebp) {
                                                                            esp = esp - 0x8;
                                                                            eax = sub_465900(&decomp_var_84, 0x0);
                                                                            if (*(sub_410b70() + 0xc) != (*(int8_t *)eax & 0xff)) {
                                                                                    sub_40b8b0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0xfffe7947;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                            else {
                                                                                    decomp_var_80 = *dword_bb7140;
                                                                                    esp = esp - 0xc;
                                                                                    decomp_var_b8 = &decomp_var_4c;
                                                                                    decomp_var_84 = 0xbb713c;
                                                                                    eax = sub_401ff0(decomp_var_b8, &decomp_var_7c, &decomp_var_84, decomp_var_ac, decomp_var_a8);
                                                                                    if (sub_401050(decomp_var_b0) != 0x0) {
                                                                                            sub_40b8b0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0xfffeb3ee;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                                    else {
                                                                                            if (decomp_var_8c == ebx) {
                                                                                                    sub_466060(&decomp_var_2c, 0x4);
                                                                                                    eax = sub_465900(&decomp_var_84, 0x0);
                                                                                                    edi = *(int8_t *)eax & 0xff;
                                                                                                    sub_465fa0();
                                                                                                    esp = esp - 0x18;
                                                                                                    if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                            if (*(int16_t *)word_4c6c08 == *(int16_t *)(sub_410b70() + 0x10)) {
                                                                                                                    esp = esp - 0xc;
                                                                                                                    decomp_var_b8 = sub_410b70() + 0x4;
                                                                                                                    if (sub_4619f0(decomp_var_b8, decomp_var_b4, decomp_var_b0) != 0x1) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0xfffe7942;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esp = esp - 0x8;
                                                                                                                            if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = 0xfffe793f;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                                    ebp = arg_10;
                                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                                    esp = esp - 0x24;
                                                                                                                                    decomp_var_c8 = ebp;
                                                                                                                                    eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                    ebx = eax;
                                                                                                                                    if (ebx != 0x0) {
                                                                                                                                            sub_40b8b0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            sub_465fa0();
                                                                                                                                            eax = ebx;
                                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                                    }
                                                                                                                                    else {
                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                                            esp = esp - 0x24;
                                                                                                                                            ecx = esi;
                                                                                                                                            decomp_var_c8 = ebp;
                                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                                            esi = eax;
                                                                                                                                            if (esi != 0x0) {
                                                                                                                                                    sub_40b8b0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = esi;
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                            }
                                                                                                                                            else {
                                                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                                    if (ecx <= 0x1) {
                                                                                                                                                            esp = esp - 0x4;
                                                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                                                    }
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    sub_465fa0();
                                                                                                                                                    eax = 0x0;
                                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe7942;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            esp = esp - 0x8;
                                                                                                            if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe793f;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                            else {
                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                    ebp = arg_10;
                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                    esp = esp - 0x24;
                                                                                                                    decomp_var_c8 = ebp;
                                                                                                                    eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                    ebx = eax;
                                                                                                                    if (ebx != 0x0) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = ebx;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                            *(sub_410b70() + 0xc);
                                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                                            decomp_var_c8 = ecx;
                                                                                                                            esp = esp - 0x24;
                                                                                                                            ecx = esi;
                                                                                                                            decomp_var_c8 = ebp;
                                                                                                                            eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                            esi = eax;
                                                                                                                            if (esi != 0x0) {
                                                                                                                                    sub_40b8b0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = esi;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                                    if (ecx <= 0x1) {
                                                                                                                                            esp = esp - 0x4;
                                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                                    }
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    sub_465fa0();
                                                                                                                                    eax = 0x0;
                                                                                                                                    *0x0 = decomp_var_c;
                                                                                                                            }
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    esp = esp - 0x8;
                                                                                                    if (sub_460a10(sub_410b70() + 0x4, decomp_var_b0) == 0x0) {
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe793d;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                                    else {
                                                                                                            decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                            esp = esp - 0x8;
                                                                                                            decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                            decomp_var_c8 = ecx;
                                                                                                            decomp_var_8c = &decomp_var_c8;
                                                                                                            eax = &decomp_var_c8;
                                                                                                            esp = esp - 0x1c;
                                                                                                            decomp_var_cc = ebp;
                                                                                                            *(int16_t *)eax = arg_10;
                                                                                                            ecx = esi;
                                                                                                            esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                            if (esi != 0x0) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = esi;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                    if (ecx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                    }
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0x0;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_40b8b0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0xfffe7947;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_40b8b0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = 0xfffe7947;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (*(int16_t *)word_4c6c10 == eax) {
                                                            esi[0xa84] = eax | 0xffffffff;
                                                            esi[0xa85] = eax | 0xffffffff;
                                                            esi[0xa86] = eax | 0xffffffff;
                                                            sub_466060(&decomp_var_2c, 0x4);
                                                            edi = sub_465930();
                                                            decomp_var_94 = edi;
                                                            sub_465fa0();
                                                            decomp_var_b0 = ecx;
                                                            decomp_var_b0 = 0x0;
                                                            eax = sub_466060(&decomp_var_2c, 0x2);
                                                            esp = esp - 0x1c;
                                                            decomp_var_b8 = &decomp_var_4c;
                                                            ebp = *sub_45fc30(decomp_var_b8, eax, decomp_var_b0);
                                                            decomp_var_7c = ebp;
                                                            sub_465fa0();
                                                            if (edi != 0x0) {
                                                                    if (edi <= 0x3) {
                                                                            if (*(sub_410b70() + 0x4) != ebp) {
                                                                                    if (*(int8_t *)(esi[0x2] + (ebp + ebp * 0x8) * 0x4 + 0x4) != 0x0) {
                                                                                            ebp = 0x0;
                                                                                            decomp_var_34 = *(sub_410b70() + 0x4);
                                                                                            if (edi > 0x0) {
                                                                                                    edi = esi + 0x2a10;
                                                                                                    while (true) {
                                                                                                            eax = sub_466060(&decomp_var_1c, 0x4);
                                                                                                            eax = sub_465900(&decomp_var_84, ebp);
                                                                                                            *edi = *(int8_t *)eax & 0xff;
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_402060(&decomp_var_2c, edi, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                                                                            decomp_var_8c = *eax;
                                                                                                            decomp_var_88 = eax[0x1];
                                                                                                            esp = esp - 0x1c;
                                                                                                            decomp_var_4c = esi[0x2] + 0x2450;
                                                                                                            eax = sub_40dfe0(&decomp_var_4c);
                                                                                                            if (eax != 0x0) {
                                                                                                                    temp_0 = 0x3;
                                                                                                                    break;
                                                                                                            }
                                                                                                            eax = *edi;
                                                                                                            eax = eax + eax * 0x8;
                                                                                                            if (*(int8_t *)(esi[0x2] + eax * 0x4 + 0x4) == 0x1) {
                                                                                                                    temp_0 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            eax = sub_410b70();
                                                                                                            esp = esp - 0x8;
                                                                                                            eax = sub_460a10(eax + 0x4, decomp_var_b0);
                                                                                                            if (eax == 0x0) {
                                                                                                                    temp_0 = 0x1;
                                                                                                                    break;
                                                                                                            }
                                                                                                            ebp = &arg_fffffffffffffffd;
                                                                                                            if (ebp != decomp_var_94) {
                                                                                                                    eax = sub_410b70();
                                                                                                                    decomp_var_34 = eax[0x1];
                                                                                                                    edi = edi + 0x4;
                                                                                                                    if (ebp < decomp_var_94) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_0 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                            eax = sub_410b70();
                                                                                                            esp = esp - 0x8;
                                                                                                            eax = sub_460a10(eax + 0x4, decomp_var_b0);
                                                                                                            if (eax != 0x0) {
                                                                                                                    edi = edi + 0x4;
                                                                                                                    if (ebp < decomp_var_94) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_0 = 0x2;
                                                                                                                    break;
                                                                                                            }
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe792e;
                                                                                                            temp_0 = 0x0;
                                                                                                            break;
                                                                                                    }
                                                                                                    switch (temp_0) {
                                                                                                        case 0:
                                                                                                            *0x0 = decomp_var_c;
                                                                                                            break;
                                                                                                        case 1:
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe7933;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                            break;
                                                                                                        case 2:
                                                                                                            decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                            decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                            eax = sub_465f60(&arg_14);
                                                                                                            decomp_var_c8 = ecx;
                                                                                                            decomp_var_8c = &decomp_var_c8;
                                                                                                            eax = &decomp_var_c8;
                                                                                                            esp = esp - 0x24;
                                                                                                            decomp_var_cc = decomp_var_7c;
                                                                                                            *(int16_t *)eax = arg_10;
                                                                                                            ecx = esi;
                                                                                                            esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                            if (esi != 0x0) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = esi;
                                                                                                            }
                                                                                                            else {
                                                                                                                    eax = decomp_var_98 - 0x10;
                                                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                    if (ecx <= 0x1) {
                                                                                                                            esp = esp - 0x4;
                                                                                                                            (*(**eax + 0x4))(eax);
                                                                                                                    }
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0x0;
                                                                                                            }
                                                                                                            *0x0 = decomp_var_c;
                                                                                                            break;
                                                                                                        default:
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe7933;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    decomp_var_b0 = *(sub_410b70() + 0xc);
                                                                                                    decomp_var_b4 = *(sub_410b70() + 0xc);
                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                    decomp_var_c8 = ecx;
                                                                                                    decomp_var_8c = &decomp_var_c8;
                                                                                                    eax = &decomp_var_c8;
                                                                                                    esp = esp - 0x24;
                                                                                                    decomp_var_cc = decomp_var_7c;
                                                                                                    *(int16_t *)eax = arg_10;
                                                                                                    ecx = esi;
                                                                                                    esi = sub_41d360(decomp_var_cc, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                    if (esi != 0x0) {
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = esi;
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                            if (ecx <= 0x1) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                            }
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0x0;
                                                                                                    }
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            sub_40b8b0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0xfffe7938;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_40b8b0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0xfffe7938;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_40b8b0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0xfffe7938;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                            }
                                                            else {
                                                                    sub_40b8b0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = 0xfffe7938;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                    }
                                                    else {
                                                            if (*(int16_t *)word_4c6c14 == eax) {
                                                                    eax = sub_466060(&decomp_var_1c, 0x2);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    eax = sub_465900(&decomp_var_84, 0x2);
                                                                    edx = *(int8_t *)eax & 0xff;
                                                                    decomp_var_84 = edx;
                                                                    eax = sub_402060(&decomp_var_2c, &decomp_var_84, decomp_var_ac, decomp_var_a8, decomp_var_a4);
                                                                    edx = *eax;
                                                                    decomp_var_90 = eax[0x1];
                                                                    decomp_var_94 = edx;
                                                                    esp = esp - 0x20;
                                                                    decomp_var_4c = esi[0x2] + 0x2450;
                                                                    eax = sub_40dfe0(&decomp_var_4c);
                                                                    if (eax != 0x0) {
                                                                            sub_40b8b0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0xfffe7929;
                                                                            *0x0 = decomp_var_c;
                                                                    }
                                                                    else {
                                                                            sub_466060(&decomp_var_1c, 0x1);
                                                                            eax = sub_465900(&decomp_var_84, 0x0);
                                                                            edi = *(int16_t *)eax;
                                                                            sub_465fa0();
                                                                            decomp_var_b0 = ecx;
                                                                            decomp_var_b0 = edi;
                                                                            eax = sub_466060(&decomp_var_1c, 0x2);
                                                                            esp = esp - 0x24;
                                                                            eax = sub_45fc30(&decomp_var_2c, eax, decomp_var_b0);
                                                                            ecx = *eax;
                                                                            ebp = eax[0x1];
                                                                            decomp_var_7c = ecx;
                                                                            sub_465fa0();
                                                                            if (ebp == *(int16_t *)(sub_410b70() + 0x8)) {
                                                                                    if (*(sub_410b70() + 0x4) == decomp_var_7c) {
                                                                                            esp = esp - 0x8;
                                                                                            eax = sub_465900(&decomp_var_84, 0x0);
                                                                                            if (*(sub_410b70() + 0xc) == (*(int8_t *)eax & 0xff)) {
                                                                                                    if (*(int16_t *)word_4c6c08 != *(int16_t *)(sub_410b70() + 0x8)) {
                                                                                                            sub_40b8b0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0xfffe7924;
                                                                                                            *0x0 = decomp_var_c;
                                                                                                    }
                                                                                                    else {
                                                                                                            decomp_var_b0 = *(int16_t *)word_4c6c08;
                                                                                                            decomp_var_b0 = edi;
                                                                                                            eax = sub_466060(&decomp_var_1c, 0x4);
                                                                                                            eax = sub_45fc30(&decomp_var_2c, eax, decomp_var_b0);
                                                                                                            edi = *eax;
                                                                                                            sub_465fa0();
                                                                                                            esp = esp - 0x20;
                                                                                                            decomp_var_b8 = sub_410b70() + 0x4;
                                                                                                            if (sub_4619f0(decomp_var_b8, decomp_var_b4, decomp_var_b0) == 0x0) {
                                                                                                                    sub_40b8b0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0xfffe791f;
                                                                                                                    *0x0 = decomp_var_c;
                                                                                                            }
                                                                                                            else {
                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                    *(sub_410b70() + 0xc);
                                                                                                                    eax = sub_465f60(&arg_14);
                                                                                                                    decomp_var_c8 = ecx;
                                                                                                                    decomp_var_c8 = arg_10;
                                                                                                                    esp = esp - 0x24;
                                                                                                                    ecx = esi;
                                                                                                                    eax = sub_41d360(edi, decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, decomp_var_b0, decomp_var_ac, decomp_var_a8, decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, &decomp_var_c8, decomp_var_88, decomp_var_84, decomp_var_80);
                                                                                                                    esi = eax;
                                                                                                                    if (esi != 0x0) {
                                                                                                                            sub_40b8b0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = esi;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            eax = decomp_var_98 - 0x10;
                                                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], ecx | 0xffffffff);
                                                                                                                            if (ecx <= 0x1) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    (*(**eax + 0x4))(eax);
                                                                                                                            }
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            sub_465fa0();
                                                                                                                            eax = 0x0;
                                                                                                                            *0x0 = decomp_var_c;
                                                                                                                    }
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    sub_40b8b0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0xfffe7924;
                                                                                                    *0x0 = decomp_var_c;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            sub_40b8b0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0xfffe7924;
                                                                                            *0x0 = decomp_var_c;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_40b8b0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0xfffe7924;
                                                                                    *0x0 = decomp_var_c;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    sub_40b8b0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = 0xfffea06f;
                                                                    *0x0 = decomp_var_c;
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    eax = decomp_var_98 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], 0xffffffff);
                                    if (ecx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = 0x0;
                                    *0x0 = decomp_var_c;
                            }
                    }
            }
    }
    return eax;
}
