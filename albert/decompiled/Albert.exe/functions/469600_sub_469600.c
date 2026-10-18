// sub_469600 @ 0x469600
// hopper name: sub_469600
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_469600() {
    var_8 = 0x49a428;
    var_C = *0x0;
    var_10 = *dword_4c8db8 ^ &var_74;
    var_7C = ebp;
    var_80 = esi;
    var_84 = edi;
    var_88 = *dword_4c8db8 ^ &var_84;
    *0x0 = &var_C;
    edi = arg_1c;
    var_4C = arg_4;
    var_60 = arg_14;
    eax = sub_465800(&var_50);
    ebp = var_50;
    esp = (esp - 0x90) + 0x4;
    ebx = sub_469210(eax);
    var_68 = ebx;
    if (ebp != 0x0) {
            esp = esp - 0x4;
            sub_4931ea(0x0);
            eax = arg_0;
            if (eax > 0x0 && eax < 0xffffffff) {
                    arg_0 = eax - 0x1;
            }
            esi = !(-arg_0 - -arg_0 + CARRY(EFLAGS(cf))) & ebp;
            sub_49320b();
            if (esi != 0x0) {
                    esp = esp - 0x4;
                    (**esi)(0x1);
            }
    }
    esp = esp - 0x4;
    eax = sub_468bc0(&var_2C);
    eax = *(*ebx + 0x8);
    (eax)();
    eax = *(int8_t *)edi;
    if (eax != 0x2b) {
            var_64 = 0x0;
            if (eax == 0x2d) {
                    var_64 = 0x1;
            }
    }
    else {
            var_64 = 0x1;
    }
    ebp = arg_2c;
    edx = *(int8_t *)*sub_47d2f9();
    var_8C = ebp;
    var_90 = 0x65;
    var_74 = edx;
    esi = sub_47bf50(edi, 0x65, var_8C);
    var_98 = ebp;
    var_9C = sign_extend_32(var_74);
    var_A0 = edi;
    eax = sub_47bf50(var_A0, var_9C, var_98);
    ebx = eax;
    esp = (esp - 0x18) + 0x18;
    ecx = var_14;
    edx = var_28;
    eax = edx;
    if (ecx < 0x10) {
            eax = &var_28;
    }
    if (*(int8_t *)eax != 0x7f) {
            eax = edx;
            if (ecx < 0x10) {
                    eax = &var_28;
            }
            if (*(int8_t *)eax > 0x0) {
                    var_8C = ebp;
                    esp = esp - 0x8;
                    var_90 = edi;
                    sub_460580();
                    if (esi == 0x0) {
                            esp = esp - 0x8;
                            var_98 = arg_20;
                            sub_4603d0();
                            ebp = arg_10;
                    }
                    else {
                            if (ebx == 0x0) {
                                    esp = esp - 0x8;
                                    var_98 = arg_18;
                                    sub_4603d0();
                                    ebp = 0x0;
                            }
                            else {
                                    ebp = arg_18;
                            }
                            esp = esp - 0xc;
                            sub_468ac0();
                    }
                    esp = esp - 0x4;
                    var_9C = 0x30;
                    if (ebx == 0x0) {
                            esp = esp - 0x4;
                            var_A0 = ebp;
                            sub_4603d0();
                    }
                    else {
                            var_A0 = arg_14;
                            sub_468ac0();
                            var_AC = ebp;
                            esp = esp - 0x14;
                            sub_468ac0();
                            saved_fp = 0x0;
                    }
                    edi = var_40;
                    if (var_2C < 0x10) {
                            edi = &var_40;
                    }
                    eax = var_5C;
                    if (var_48 < 0x10) {
                            eax = &var_5C;
                    }
                    var_A4 = &var_8C;
                    esi = sub_47d320(eax, var_A4);
                    eax = *(int8_t *)edi;
                    esp = (esp - 0x8) + 0x8;
                    if (eax != 0x7f) {
                            while (true) {
                                    if (eax <= 0x0) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    eax = sign_extend_32(eax);
                                    if (eax >= esi - var_7C) {
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    var_A4 = 0x0;
                                    esi = esi - eax;
                                    esp = esp - 0xc;
                                    var_AC = esi;
                                    sub_468ac0();
                                    if (edi[0x1] > 0x0) {
                                            edi = edi + 0x1;
                                    }
                                    eax = *(int8_t *)edi;
                                    if (eax != 0x7f) {
                                            continue;
                                    }
                                    temp_0 = 0x1;
                                    break;
                            }
                    }
                    edi = var_68;
                    if (var_54 < 0x10) {
                            edi = &var_68;
                    }
                    arg_4 = 0x0;
                    arg_8 = var_58;
                    ebp = var_58;
            }
    }
    edx = var_84;
    ecx = edx[0x6];
    eax = saved_fp + arg_0 + arg_4 + ebp;
    if (ecx > 0x0 && ecx > eax) {
            var_94 = ecx - eax;
    }
    else {
            var_94 = 0x0;
    }
    eax = edx[0x4];
    esi = var_20;
    eax = eax & 0x1c0;
    switch (eax) {
        case 64:
            ebx = var_14;
            ebp = var_18;
            break;
        case 256:
            if (var_88 > 0x0) {
                    decomp_var_c0 = var_18;
                    eax = sub_4688b0(esi, &var_80, decomp_var_c0, var_14, var_10, edi, 0x1);
                    ebx = *eax;
                    edx = eax[0x1];
                    ecx = eax[0x2];
                    esp = (esp - 0x1c) + 0x1c;
                    edi = edi + 0x1;
                    arg_8 = &var_4;
            }
            else {
                    ecx = var_10;
                    edx = var_14;
                    ebx = var_18;
            }
            decomp_var_c0 = ebx;
            decomp_var_bc = edx;
            decomp_var_c4 = &var_80;
            decomp_var_c8 = esi;
            eax = sub_468930(decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, ecx, var_8, var_94);
            edx = eax[0x2];
            ebp = *eax;
            ebx = eax[0x1];
            esp = (esp - 0x1c) + 0x1c;
            var_10 = edx;
            break;
        default:
            decomp_var_c0 = var_18;
            decomp_var_bc = var_14;
            decomp_var_c4 = &var_80;
            decomp_var_c8 = esi;
            eax = sub_468930(decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, var_10, var_8, var_94);
            ecx = eax[0x2];
            ebp = *eax;
            ebx = eax[0x1];
            esp = (esp - 0x1c) + 0x1c;
            var_10 = ecx;
            break;
    }
    var_B0 = arg_8;
    decomp_var_b4 = sign_extend_32(var_98);
    decomp_var_b8 = edi;
    eax = sub_47bf50(decomp_var_b8, decomp_var_b4, var_B0);
    esp = (esp - 0xc) + 0xc;
    if (eax != 0x0) {
            decomp_var_c4 = ebp;
            decomp_var_c0 = ebx;
            eax = sub_4689b0(esi, &var_80, decomp_var_c4, decomp_var_c0, var_10, edi, (eax - edi) + 0x1 - 0x1, var_90);
            var_B0 = saved_fp;
            decomp_var_b4 = 0x30;
            decomp_var_c0 = *eax;
            decomp_var_bc = eax[0x1];
            decomp_var_b8 = eax[0x2];
            decomp_var_c4 = &var_80;
            decomp_var_c8 = esi;
            eax = sub_468930(decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, 0x30, var_B0);
            edx = eax[0x2];
            ebx = *eax;
            ebp = eax[0x1];
            var_10 = edx;
            eax = (*(*var_8C + 0x4))();
            decomp_var_dc = ebx;
            eax = sub_468930(esi, &var_9C, decomp_var_dc, ebp, var_2C, eax, 0x1);
            decomp_var_dc = *eax;
            edx = eax[0x1];
            eax = eax[0x2];
            decomp_var_e0 = &var_9C;
            esp = (((esp - 0x20) + 0x20 - 0x1c) + 0x1c - 0x1c) + 0x1c - 0x1c;
            eax = sub_468930(esi, decomp_var_e0, decomp_var_dc, edx, eax, 0x30, var_18);
            edx = eax[0x2];
            ebp = *eax;
            ebx = eax[0x1];
            esp = esp + 0x1c;
            edi = edi + var_A4;
            var_10 = var_10 - var_A4;
            var_2C = edx;
    }
    eax = sub_47bf50(edi, 0x65, var_10);
    esp = (esp - 0xc) + 0xc;
    if (eax != 0x0) {
            var_A8 = (eax - edi) + 0x1;
            decomp_var_e0 = ebp;
            decomp_var_dc = ebx;
            eax = sub_4689b0(esi, &var_9C, decomp_var_e0, decomp_var_dc, var_2C, edi, (eax - edi) + 0x1 - 0x1, var_AC);
            decomp_var_dc = *eax;
            edx = eax[0x1];
            eax = eax[0x2];
            eax = sub_468930(esi, &var_9C, decomp_var_dc, edx, eax, 0x30, var_14);
            esp = ((esp - 0x20) + 0x20 - 0x1c) + 0x1c;
            var_14 = 0x0;
            ecx = 0x4b1dd8;
            if ((var_A0[0x10] & 0x4) == 0x0) {
                    ecx = 0x4b1dd4;
            }
            decomp_var_dc = *eax;
            edx = eax[0x1];
            eax = eax[0x2];
            decomp_var_e0 = &var_9C;
            eax = sub_4688b0(esi, decomp_var_e0, decomp_var_dc, edx, eax, ecx, 0x1);
            ebp = *eax;
            ebx = eax[0x1];
            ecx = eax[0x2];
            esp = (esp - 0x1c) + 0x1c;
            edi = edi + var_A8;
            var_10 = var_10 - var_A8;
    }
    else {
            ecx = var_2C;
    }
    decomp_var_e0 = ebp;
    eax = sub_4689b0(esi, &var_9C, decomp_var_e0, ebx, ecx, edi, var_10, var_AC);
    decomp_var_dc = *eax;
    edx = eax[0x1];
    eax = eax[0x2];
    eax = sub_468930(esi, &var_9C, decomp_var_dc, edx, eax, 0x30, var_14);
    edi = eax[0x1];
    edx = *eax;
    eax = eax[0x2];
    var_A0[0x6] = 0x0;
    decomp_var_dc = edx;
    decomp_var_d8 = edi;
    edi = var_8C;
    sub_468930(esi, edi, decomp_var_dc, decomp_var_d8, eax, var_24, var_B0);
    esp = (((esp - 0x20) + 0x20 - 0x1c) + 0x1c - 0x1c) + 0x1c;
    if (var_70 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    if (var_54 >= 0x10) {
            sub_47c8f9();
            esp = (esp - 0x4) + 0x4;
    }
    *0x0 = var_4C;
    eax = sub_47ad69();
    return eax;
}
