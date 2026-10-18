// sub_46b050 @ 0x46b050
// hopper name: sub_46b050
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_46b050() {
    var_C = *0x0;
    decomp_var_c4 = ebx;
    decomp_var_c8 = ebp;
    decomp_var_cc = esi;
    decomp_var_d0 = edi;
    decomp_var_d4 = *dword_4c8db8 ^ &decomp_var_d0;
    *0x0 = &var_C;
    ebx = ecx;
    edi = 0x0;
    esp = esp - 0xdc;
    var_B4 = 0x0;
    sub_46a890(0x2, 0x1);
    var_4 = 0x1;
    var_BF = 0x0;
    var_B8 = sub_46db50();
    var_BC = 0x0;
    if (ebx[0x1] <= 0x0) goto loc_46b234;
    goto loc_46b0b8;

loc_46b234:
    sub_4684c0(arg_8);
    sub_467170();
    var_38 = 0x4b1c3c;
    sub_493590(&var_38);
    eax = arg_8;
    *0x0 = var_4;
    return eax;

loc_46b0b8:
    if (var_BF != 0x0) {
            esi = edi + edi;
            if (*(int8_t *)(esi + *ebx + 0x1) != 0x4b) {
                    eax = sub_46a2b0(&var_8C, 0x4b1e1c);
                    esp = (esp - 0x8) + 0x8;
                    var_BF = 0x0;
                    edx = *ebx;
                    esi = edi + edi;
                    ecx = *(int16_t *)(esi + edx) & 0xffff;
                    eax = esi + edx;
                    if (HIBYTE(ecx) == 0x4b) {
                            eax = sub_46a2b0(&var_8C, 0x4b1974);
                            esp = (esp - 0x8) + 0x8;
                            var_BF = 0x1;
                            decomp_var_d4 = *(int8_t *)(esi + *ebx) & 0xff;
                            eax = sub_46a070(&var_88, decomp_var_d4);
                            esp = (esp - 0x8) + 0x8;
                            edi = var_B4 + 0x1;
                            var_B4 = edi;
                            if (edi < ebx[0x1]) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            if (var_BF != 0x0) {
                                    decomp_var_d4 = *(int8_t *)(esi + *ebx) & 0xff;
                                    eax = sub_46a070(&var_88, decomp_var_d4);
                                    esp = (esp - 0x8) + 0x8;
                                    edi = var_B4 + 0x1;
                                    var_B4 = edi;
                                    if (edi < ebx[0x1]) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if ((ecx & 0xc000) == 0x0) {
                                            eax = *(int16_t *)eax & 0xffff;
                                            bool_7 = (eax & 0x2000) == 0x0;
                                            eax = eax & 0xffff;
                                            if (!bool_7) {
                                                    eax = eax | 0xffffe000;
                                            }
                                            sub_46a2b0(sub_46a740(eax), decomp_var_d8);
                                            esp = (esp - 0xc) + 0x8;
                                    }
                                    else {
                                            var_BE = *(int16_t *)eax;
                                            esp = esp - 0x8;
                                            eax = sub_467570(&var_B0, &var_BE, decomp_var_d4, decomp_var_d0, decomp_var_cc);
                                            esi = *eax;
                                            edi = eax[0x1];
                                            ebp = arg_0;
                                            if (esi == 0x0 || esi != var_B8) {
                                                    sub_47a948();
                                            }
                                            if (edi == ebp) {
                                                    eax = sub_46a2b0(&var_8C, 0x4b1e14);
                                                    esp = (esp - 0x8) + 0x8;
                                            }
                                            else {
                                                    if (esi == 0x0) {
                                                            sub_47a948();
                                                    }
                                                    if (edi == esi[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    eax = sub_460d20(&var_A8, edi + 0x10, 0x4af9d0);
                                                    eax = sub_46a4c0(&var_8C, eax);
                                                    esp = (esp - 0x14) + 0x14;
                                                    var_4 = 0x1;
                                                    if (var_90 >= 0x10) {
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                            }
                                    }
                                    edi = var_B4 + 0x1;
                                    var_B4 = edi;
                                    if (edi < ebx[0x1]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
            else {
                    decomp_var_d4 = *(int8_t *)(esi + *ebx) & 0xff;
                    eax = sub_46a070(&var_88, decomp_var_d4);
                    esp = (esp - 0x8) + 0x8;
                    edi = var_B4 + 0x1;
                    var_B4 = edi;
                    if (edi < ebx[0x1]) {
                            continue;
                    }
                    break;
            }
    }
    else {
            edx = *ebx;
            esi = edi + edi;
            ecx = *(int16_t *)(esi + edx) & 0xffff;
            eax = esi + edx;
            if (HIBYTE(ecx) == 0x4b) {
                    eax = sub_46a2b0(&var_8C, 0x4b1974);
                    esp = (esp - 0x8) + 0x8;
                    var_BF = 0x1;
                    decomp_var_d4 = *(int8_t *)(esi + *ebx) & 0xff;
                    eax = sub_46a070(&var_88, decomp_var_d4);
                    esp = (esp - 0x8) + 0x8;
                    edi = var_B4 + 0x1;
                    var_B4 = edi;
                    if (edi < ebx[0x1]) {
                            continue;
                    }
                    break;
            }
            else {
                    if (var_BF != 0x0) {
                            decomp_var_d4 = *(int8_t *)(esi + *ebx) & 0xff;
                            eax = sub_46a070(&var_88, decomp_var_d4);
                            esp = (esp - 0x8) + 0x8;
                            edi = var_B4 + 0x1;
                            var_B4 = edi;
                            if (edi < ebx[0x1]) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            if ((ecx & 0xc000) == 0x0) {
                                    eax = *(int16_t *)eax & 0xffff;
                                    bool_28 = (eax & 0x2000) == 0x0;
                                    eax = eax & 0xffff;
                                    if (!bool_28) {
                                            eax = eax | 0xffffe000;
                                    }
                                    sub_46a2b0(sub_46a740(eax), decomp_var_d8);
                                    esp = (esp - 0xc) + 0x8;
                            }
                            else {
                                    var_BE = *(int16_t *)eax;
                                    esp = esp - 0x8;
                                    eax = sub_467570(&var_B0, &var_BE, decomp_var_d4, decomp_var_d0, decomp_var_cc);
                                    esi = *eax;
                                    edi = eax[0x1];
                                    ebp = arg_0;
                                    if (esi == 0x0 || esi != var_B8) {
                                            sub_47a948();
                                    }
                                    if (edi == ebp) {
                                            eax = sub_46a2b0(&var_8C, 0x4b1e14);
                                            esp = (esp - 0x8) + 0x8;
                                    }
                                    else {
                                            if (esi == 0x0) {
                                                    sub_47a948();
                                            }
                                            if (edi == esi[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = sub_460d20(&var_A8, edi + 0x10, 0x4af9d0);
                                            eax = sub_46a4c0(&var_8C, eax);
                                            esp = (esp - 0x14) + 0x14;
                                            var_4 = 0x1;
                                            if (var_90 >= 0x10) {
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                    }
                            }
                            edi = var_B4 + 0x1;
                            var_B4 = edi;
                            if (edi < ebx[0x1]) {
                                    continue;
                            }
                            break;
                    }
            }
    }
    goto .l2;

.l2:
    if (var_B7 != 0x0) {
            eax = sub_46a2b0(&var_84, 0x4b1e1c);
            esp = (esp - 0x8) + 0x8;
    }
    goto loc_46b234;
}
