// Replies @ 0x42c970
// hopper name: sub_42c970
// pybert name: Replies
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_e9a993000f42e2a2822f92ee890545c1f90f30005982b619aae5f64a2cd0d443
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

Replies() {
    decomp_var_c = *0x0;
    decomp_var_a0 = ebx;
    decomp_var_a4 = ebp;
    decomp_var_a8 = esi;
    decomp_var_ac = edi;
    esp = esp - 0xb0;
    decomp_var_b0 = *dword_4c8db8 ^ &decomp_var_ac;
    *0x0 = &decomp_var_c;
    esi = ecx;
    decomp_var_99 = 0x0;
    eax = sub_47020b();
    if (eax != 0x0) goto loc_42c9c9;
    goto loc_42c9bf;

loc_42c9c9:
    decomp_var_98 = (*(*eax + 0xc))() + 0x10;
    ecx = arg_10;
    if (ecx != (*(int8_t *)(esi[0x2] + 0x2424) & 0xff)) {
            esp = esp - 0x4;
            sub_421570(ecx);
    }
    edx = *dword_bb65cc;
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    decomp_var_8c = 0xbb65c8;
    decomp_var_88 = **dword_bb65cc;
    goto loc_42ca13;

loc_42c9bf:
    eax = sub_40b5a0(0x80004005);
    return eax;

loc_42ca13:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_465d90(&arg_0);
            if (eax == 0x0) {
                    sub_40f860();
                    esi = decomp_var_88;
                    edi = decomp_var_8c;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x20] != 0x0) {
                    sub_40f860();
                    esi = decomp_var_88;
                    edi = decomp_var_8c;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_1c;
            decomp_var_68 = arg_20;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&decomp_var_5c, &arg_10, decomp_var_b0, decomp_var_ac, decomp_var_a8);
            ecx = eax;
            eax = *ecx;
            decomp_var_94 = ecx;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
                    ecx = decomp_var_94;
            }
            edx = decomp_var_68;
            if (ecx[0x1] == edx) {
                    sub_40f860();
                    esi = decomp_var_88;
                    edi = decomp_var_8c;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            ebx = &arg_28;
            decomp_var_70 = arg_2c;
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = &decomp_var_54;
            esp = esp - 0x8;
            eax = sub_401ff0(edx, &arg_10, decomp_var_b0, decomp_var_ac, decomp_var_a8);
            ecx = eax;
            eax = *ecx;
            decomp_var_94 = ecx;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
                    ecx = decomp_var_94;
            }
            if (ecx[0x1] == decomp_var_70) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &decomp_var_30;
                    esp = esp - 0x8;
                    eax = sub_404ce0(edx, &arg_10, decomp_var_b0);
            }
            if (*(int16_t *)word_4c6d48 != arg_14) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    ebx = &arg_34;
                    decomp_var_78 = arg_38;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    edx = &arg_10;
                    esp = esp - 0x8;
                    eax = sub_401ff0(&decomp_var_64, edx, decomp_var_b0, decomp_var_ac, decomp_var_a8);
                    eax = *eax;
                    if (eax == 0x0 || eax != ebx) {
                            sub_47a948();
                    }
                    if (arg_0 == decomp_var_78) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x8;
                            eax = sub_404ce0(&decomp_var_18, &arg_10, decomp_var_b0);
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            edx = *(esi[0x16] + 0x4);
                            esp = esp - 0x4;
                            sub_410cf0(edx);
                            eax = *(esi + 0x58);
                            eax[0x1] = eax;
                            eax = *(esi + 0x58);
                            *(esi + 0x5c) = 0x0;
                            *eax = eax;
                            esi = *(esi + 0x58);
                            esi[0x2] = esi;
                    }
            }
            decomp_var_99 = 0x1;
            esi = (sub_47b26f(0x0) - *dword_ba2880) + 0x2710;
            esp = (esp - 0x4) + 0x4 - 0x4;
            eax = sub_46b050(&decomp_var_4c, decomp_var_b0, decomp_var_ac);
            if (eax[0x6] >= 0x10) {
                    edi = eax[0x1];
            }
            else {
                    edi = eax + 0x4;
            }
            esp = esp - 0x4;
            sub_46db50();
            eax = sub_4273a0(decomp_var_b4);
            if (eax[0x6] >= 0x10) {
                    eax = eax[0x1];
            }
            else {
                    eax = eax + 0x4;
            }
            eax = sub_410c10(&decomp_var_98, "We have received a reply: %s to %s", eax);
            esp = (esp - 0x10) + 0x10;
            if (decomp_var_34 >= 0x10) {
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
            }
            esi = sub_40bfa0(decomp_var_98 - 0x10) + 0x10;
            esp = (esp - 0x4) + 0x4 - 0x8;
            eax = sub_419e60(&decomp_var_24, &decomp_var_84, decomp_var_b0);
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            edx = edx - 0x1;
            if (edx <= 0x0) {
                    edx = **eax;
                    esp = esp - 0x4;
                    (edx[0x1])(eax);
            }
            sub_40f860();
            esi = decomp_var_88;
            edi = decomp_var_8c;
            continue;
    }
    break;
    eax = decomp_var_98 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_465fa0();
    eax = decomp_var_99;
    *0x0 = decomp_var_c;
    return eax;
}
