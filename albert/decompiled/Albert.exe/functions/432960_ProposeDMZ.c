// ProposeDMZ @ 0x432960
// hopper name: sub_432960
// pybert name: ProposeDMZ
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ProposeDMZ() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_8 = 0x49710a;
    var_C = *0x0;
    decomp_var_c0 = ebx;
    decomp_var_c4 = esi;
    var_C8 = edi;
    esp = esp - 0xcc;
    decomp_var_cc = *dword_4c8db8 ^ &var_C8;
    *0x0 = &var_C;
    var_80 = ecx;
    var_AE = 0x0;
    var_B4 = 0x0;
    var_B8 = 0x0;
    var_A4 = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    eax = *dword_4c6bd4;
    edx = *dword_bb6f20;
    ecx = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    edi = *edx;
    esi = (SAR(eax + ((eax & 0x80000000 ? 0xffffffff : 0x0) & 0x3), 0x2)) - 0x4;
    ebx = 0xbb6f1c;
    var_84 = esi;
    var_64 = ecx;
    var_AC = 0xbb6f1c;
    var_A8 = edi;
    goto loc_432a20;

loc_432a20:
    var_78 = *dword_bb6f20;
    if (ebx == 0x0 || ebx != 0xbb6f1c) {
            sub_47a948();
    }
    if (edi == var_78) goto loc_432c31;
    goto loc_432a44;

loc_432c31:
    eax = sub_465930();
    var_7C = eax;
    if (eax <= 0x1) goto loc_432e91;
    goto loc_432c4a;

loc_432a44:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    if (edi[0x5] != arg_0) {
            sub_40f6f0();
            edi = var_A8;
            ebx = var_AC;
            esi = var_84;
            continue;
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    if (edi[0x10] != 0x0) {
            sub_40f6f0();
            edi = var_A8;
            ebx = var_AC;
            esi = var_84;
            continue;
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    if (edi[0x3] <= esi) {
            sub_40f6f0();
            edi = var_A8;
            ebx = var_AC;
            esi = var_84;
            continue;
    }
    bool_29 = edi != ebx[0x1];
    esi = (arg_0 + arg_0 * 0x2) * 0x4 + 0xbb7028;
    var_1C = *((arg_0 + arg_0 * 0x2) * 0x4 + 0xbb702c);
    if (!bool_29) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_401ff0(&var_98, edi + 0x18, decomp_var_cc, var_C8, decomp_var_c4);
    var_88 = eax;
    eax = *eax;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (var_88[0x1] != var_1C) {
            sub_40f6f0();
            edi = var_A8;
            ebx = var_AC;
            esi = var_84;
            continue;
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    if (edi[0x1c] != 0x1) {
            sub_40f6f0();
            edi = var_A8;
            ebx = var_AC;
            esi = var_84;
            continue;
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    if (edi[0x1d] != 0x1) {
            sub_40f6f0();
            edi = var_A8;
            ebx = var_AC;
            esi = var_84;
            continue;
    }
    if (*(int8_t *)(sub_410b70() + 0x12) != 0x0) {
            sub_40f6f0();
            edi = var_A8;
            ebx = var_AC;
            esi = var_84;
            continue;
    }
    ebx = **dword_bb7134;
    esi = 0xbb7130;
    var_B9 = 0x0;
    var_A0 = 0xbb7130;
    var_9C = **dword_bb7134;
    eax = sub_432b40(decomp_var_cc, var_C8, decomp_var_c4, decomp_var_c0, decomp_var_bc, var_B8, var_B4, var_B0, var_AC, var_A8, var_A4, 0xbb7130, **dword_bb7134, var_98, var_94, var_90, decomp_var_8c, var_88, var_84);
    temp_1 = 0x0;
    break;

loc_432e91:
    eax = *dword_bb6f20;
    esi = **dword_bb6f20;
    ebx = 0xbb6f1c;
    var_AC = 0xbb6f1c;
    var_A8 = **dword_bb6f20;
    goto loc_432ea5;

loc_432c4a:
    var_84 = 0x0;
    if (eax > 0x0) {
            eax = arg_0;
            var_98 = eax;
            temp_1 = 0x1;
    }
    else {
            temp_1 = 0x2;
    }
    goto .l86;
    if (temp_1 == 0x0) goto .l1;
    goto .l76;

loc_432ea5:
    if (ebx == 0x0 || ebx != 0xbb6f1c) {
            eax = sub_47a948();
    }
    edi = *dword_bb6f20;
    if (esi != *dword_bb6f20) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x5] != arg_0) {
                    eax = sub_40f6f0();
                    esi = var_A8;
                    ebx = var_AC;
                    continue;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x10] != 0x0) {
                    eax = sub_40f6f0();
                    esi = var_A8;
                    ebx = var_AC;
                    continue;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x3] <= var_84) {
                    eax = sub_40f6f0();
                    esi = var_A8;
                    ebx = var_AC;
                    continue;
            }
            bool_38 = esi != ebx[0x1];
            edi = (arg_0 + arg_0 * 0x2) * 0x4 + 0xbb7028;
            var_70 = edi[0x1];
            if (!bool_38) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_98, esi + 0x18, decomp_var_cc, var_C8, decomp_var_c4);
            var_7C = eax;
            eax = *eax;
            if (eax == 0x0 || eax != edi) {
                    sub_47a948();
            }
            if (var_7C[0x1] != var_70) {
                    eax = sub_40f6f0();
                    esi = var_A8;
                    ebx = var_AC;
                    continue;
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi[0x1c] == 0x1) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x1d] == 0x1) {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1e] != 0x0) {
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1c] != 0x1) {
                                            eax = sub_40f6f0();
                                            esi = var_A8;
                                            ebx = var_AC;
                                            continue;
                                    }
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1d] != 0x0) {
                                            eax = sub_40f6f0();
                                            esi = var_A8;
                                            ebx = var_AC;
                                            continue;
                                    }
                                    if (esi == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    if (esi[0x1e] != 0x0) {
                                            eax = sub_40f6f0();
                                            esi = var_A8;
                                            ebx = var_AC;
                                            continue;
                                    }
                                    eax = *dword_bb7134;
                                    edi = **dword_bb7134;
                                    ebx = 0xbb7130;
                                    var_B9 = 0x0;
                                    var_A0 = 0xbb7130;
                                    var_9C = **dword_bb7134;
                                    temp_0 = 0x1;
                                    break;
                            }
                            else {
                                    edi = **dword_bb7134;
                                    eax = 0xbb7130;
                                    var_B9 = 0x0;
                                    var_A0 = 0xbb7130;
                                    var_9C = **dword_bb7134;
                                    temp_0 = 0x0;
                                    break;
                            }
                    }
                    else {
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1c] != 0x1) {
                                    eax = sub_40f6f0();
                                    esi = var_A8;
                                    ebx = var_AC;
                                    continue;
                            }
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1d] != 0x0) {
                                    eax = sub_40f6f0();
                                    esi = var_A8;
                                    ebx = var_AC;
                                    continue;
                            }
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (esi[0x1e] != 0x0) {
                                    eax = sub_40f6f0();
                                    esi = var_A8;
                                    ebx = var_AC;
                                    continue;
                            }
                            eax = *dword_bb7134;
                            edi = **dword_bb7134;
                            ebx = 0xbb7130;
                            var_B9 = 0x0;
                            var_A0 = 0xbb7130;
                            var_9C = **dword_bb7134;
                            temp_0 = 0x1;
                            break;
                    }
            }
            else {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x1c] != 0x1) {
                            eax = sub_40f6f0();
                            esi = var_A8;
                            ebx = var_AC;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x1d] != 0x0) {
                            eax = sub_40f6f0();
                            esi = var_A8;
                            ebx = var_AC;
                            continue;
                    }
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (esi[0x1e] != 0x0) {
                            eax = sub_40f6f0();
                            esi = var_A8;
                            ebx = var_AC;
                            continue;
                    }
                    eax = *dword_bb7134;
                    edi = **dword_bb7134;
                    ebx = 0xbb7130;
                    var_B9 = 0x0;
                    var_A0 = 0xbb7130;
                    var_9C = **dword_bb7134;
                    temp_0 = 0x1;
                    break;
            }
    }
    else {
            temp_0 = 0x2;
            break;
    }
    goto .l4;

.l86:
    break;

.l1:
    return eax;

.l76:
    if (temp_1 == 0x1) goto loc_432c61;
    goto .l77;

.l4:
    switch (temp_0) {
        case 0:
            temp_1 = 0x3;
            break;
        case 1:
            temp_1 = 0x4;
            break;
        default:
            temp_1 = 0x5;
            break;
    }
    goto .l86;

loc_432c61:
    eax = sub_465900(&var_AE, var_84);
    var_88 = *(int8_t *)eax & 0xff;
    esp = esp - 0x10;
    eax = sub_419df0(&var_74, &var_98, decomp_var_cc);
    edi = **dword_bb6f20;
    esi = 0xbb6f1c;
    var_AC = 0xbb6f1c;
    var_A8 = **dword_bb6f20;
    goto loc_432cb4;

.l77:
    if (temp_1 == 0x2) goto .l2;
    goto .l78;

loc_432cb4:
    if (esi == 0x0 || esi != 0xbb6f1c) {
            sub_47a948();
    }
    if (edi != *dword_bb6f20) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x5] != arg_0) {
                    sub_40f6f0();
                    edi = var_A8;
                    esi = var_AC;
                    continue;
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] == var_88) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    edi[0x10] = 0x1;
            }
            sub_40f6f0();
            edi = var_A8;
            esi = var_AC;
            continue;
    }
    break;

.l2:
    var_B8 = arg_0 & 0xff | 0x4100;
    eax = sub_466540(&var_20, &var_B8);
    sub_466f80(&var_74, eax);
    eax = sub_466c40(&var_98, &var_30);
    eax = sub_466f80(&var_40, eax);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465f30(&var_B8);
    sub_465ff0(&var_98);
    sub_465fa0();
    sub_465f60(&var_60);
    esp = esp - 0x54;
    sub_465f60(&var_50);
    sub_431940();
    var_AA = 0x1;
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = var_AA;
    *0x0 = var_8;
    &var_B8 = ebp;
    return eax;

.l78:
    if (temp_1 == 0x3) goto loc_432ff0;
    goto .l79;
    eax = var_84 + 0x1;
    var_84 = eax;
    if (eax < var_7C) {
            continue;
    }
    break;

loc_432ff0:
    var_70 = *dword_bb7134;
    eax = var_A0;
    if (eax == 0x0 || eax != 0xbb7130) {
            sub_47a948();
    }
    if (edi != var_70) {
            if (var_A0 == 0x0) {
                    sub_47a948();
            }
            if (edi == var_A0[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] != arg_0) {
                    sub_40e680();
                    edi = var_9C;
                    continue;
            }
            if (edi == var_A0[0x1]) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x4] != esi[0x6]) {
                    sub_40e680();
                    edi = var_9C;
                    continue;
            }
            var_B9 = 0x1;
            if (edi == var_A0[0x1]) {
                    sub_47a948();
            }
            if (edi[0x5] >= 0x2) {
                    sub_40e680();
                    edi = var_9C;
                    continue;
            }
            if (edi == var_A0[0x1]) {
                    sub_47a948();
                    temp_2 = 0x1;
            }
            else {
                    temp_2 = 0x1;
            }
            break;
    }
    else {
            if (var_B9 == 0x0) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                            temp_2 = 0x2;
                    }
                    else {
                            temp_2 = 0x2;
                    }
            }
            else {
                    temp_2 = 0x0;
            }
            break;
    }
    goto .l6;

.l79:
    if (temp_1 == 0x4) goto loc_433270;
    goto loc_4334b0;
    var_B8 = arg_0 & 0xff | 0x4100;
    eax = sub_466540(&var_20, &var_B8);
    sub_466f80(&var_74, eax);
    eax = sub_466c40(&var_98, &var_30);
    eax = sub_466f80(&var_40, eax);
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465f30(&var_B8);
    sub_465ff0(&var_98);
    sub_465fa0();
    sub_465f60(&var_60);
    esp = esp - 0x54;
    sub_465f60(&var_50);
    sub_431940();
    var_AA = 0x1;
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = var_AA;
    *0x0 = var_8;
    &var_B8 = ebp;
    return eax;

.l6:
    if (temp_2 != 0x0) {
            if (temp_2 != 0x1) {
                    var_94 = esi[0x6];
                    esp = esp - 0x8;
                    var_98 = arg_0;
                    sub_419df0(&var_74, &var_98, decomp_var_cc);
            }
            else {
                    edi[0x5] = edi[0x5] + 0x1;
            }
            var_B4 = arg_0 & 0xff | 0x4100;
            var_B0 = var_60 & 0xff | 0x4100;
            bool_2 = esi != ebx[0x1];
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = sub_466540(&var_1C, &var_B4);
            sub_466f80(&var_70, eax);
            eax = sub_466e10(&var_94, &var_A0);
            eax = sub_466f80(&var_3C, eax);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465f30(&var_B4);
            sub_465ff0(&var_94);
            sub_465fa0();
            eax = sub_465f60(&var_5C);
            esp = esp - 0x54;
            eax = sub_465f60(&var_4C);
            sub_431940();
            if (!bool_2) {
                    sub_47a948();
            }
            esi[0x10] = 0x1;
            var_AA = 0x1;
    }
    goto loc_4334b0;

loc_433270:
    var_70 = *dword_bb7134;
    if (ebx == 0x0 || ebx != 0xbb7130) {
            sub_47a948();
    }
    if (edi != var_70) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] != arg_0) {
                    sub_40e680();
                    edi = var_9C;
                    ebx = var_A0;
                    continue;
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (esi == var_AC[0x1]) {
                    sub_47a948();
            }
            if (edi[0x4] != esi[0x6]) {
                    sub_40e680();
                    edi = var_9C;
                    ebx = var_A0;
                    continue;
            }
            var_B9 = 0x1;
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x5] >= 0x2) {
                    sub_40e680();
                    edi = var_9C;
                    ebx = var_A0;
                    continue;
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
                    temp_3 = 0x1;
            }
            else {
                    temp_3 = 0x1;
            }
            break;
    }
    else {
            if (var_B9 == 0x0) {
                    if (esi == var_AC[0x1]) {
                            sub_47a948();
                            temp_3 = 0x2;
                    }
                    else {
                            temp_3 = 0x2;
                    }
            }
            else {
                    temp_3 = 0x0;
            }
            break;
    }
    goto .l5;

loc_4334b0:
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = var_AA;
    *0x0 = var_8;
    &var_B8 = ebp;
    return eax;

.l5:
    if (temp_3 != 0x0) {
            if (temp_3 != 0x1) {
                    var_94 = esi[0x6];
                    esp = esp - 0x8;
                    var_98 = arg_0;
                    sub_419df0(&var_74, &var_98, decomp_var_cc);
            }
            else {
                    edi[0x5] = edi[0x5] + 0x1;
            }
            var_B4 = arg_0 & 0xff | 0x4100;
            bool_3 = esi != var_A8[0x1];
            if (esi == var_A8[0x1]) {
                    sub_47a948();
            }
            sub_466ed0(&var_70, &var_B4);
            eax = sub_466e10(&var_94, &var_A0);
            eax = sub_466f80(&var_3C, eax);
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465f30(&var_B4);
            sub_465ff0(&var_94);
            sub_465fa0();
            eax = sub_465f60(&var_5C);
            esp = esp - 0x4c;
            eax = sub_465f60(&var_4C);
            sub_431940();
            if (!bool_3) {
                    sub_47a948();
            }
            esi[0x10] = 0x1;
            var_AA = 0x1;
    }
    goto loc_4334b0;
}
