// sub_4909a9 @ 0x4909a9
// hopper name: sub_4909a9
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4909a9() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_80 = ebx;
    decomp_var_84 = esi;
    var_7C = arg_0;
    ecx = 0x0;
    esp = esp - 0xc;
    decomp_var_88 = edi;
    var_70 = arg_4;
    edi = &var_20;
    var_74 = 0x0;
    var_68 = 0x1;
    var_4C = 0x0;
    var_58 = 0x0;
    var_5C = 0x0;
    var_60 = 0x0;
    var_64 = 0x0;
    var_50 = 0x0;
    var_6C = 0x0;
    if (arg_1c != 0x0) goto loc_490a11;
    goto loc_4909f2;

loc_490a11:
    edx = arg_8;
    var_54 = edx;
    while (true) {
            eax = *(int8_t *)edx;
            if (eax == 0x20) {
                    edx = edx + 0x1;
                    continue;
            }
            if (eax == 0x9) {
                    edx = edx + 0x1;
                    continue;
            }
            if (eax == 0xa) {
                    edx = edx + 0x1;
                    continue;
            }
            if (eax != 0xd) {
                    break;
            }
            edx = edx + 0x1;
    }
    temp_0 = 0x20;
    while (true) {
            if (temp_0 != 0xd) {
                    eax = *(int8_t *)edx;
                    edx = edx + 0x1;
                    if (ecx <= 0xb) {
                            if (*(ecx * 0x4 + switch_table) != 0x0) {
                                    if (*(ecx * 0x4 + switch_table) != 0x1) {
                                            if (*(ecx * 0x4 + switch_table) != 0x2) {
                                                    if (*(ecx * 0x4 + switch_table) != 0x3) {
                                                            if (*(ecx * 0x4 + switch_table) != 0x4) {
                                                                    if (*(ecx * 0x4 + switch_table) != 0x5) {
                                                                            if (*(ecx * 0x4 + switch_table) != 0x6) {
                                                                                    if (*(ecx * 0x4 + switch_table) != 0x7) {
                                                                                            if (*(ecx * 0x4 + switch_table) != 0x8) {
                                                                                                    if (*(ecx * 0x4 + switch_table) != 0x9) {
                                                                                                            if (*(ecx * 0x4 + switch_table) != 0xa) {
                                                                                                                    if (arg_18 != 0x0) {
                                                                                                                            eax = sign_extend_32(eax) - 0x2b;
                                                                                                                            ecx = edx - 0x1;
                                                                                                                            var_54 = ecx;
                                                                                                                            if (eax == 0x0) {
                                                                                                                                    esp = esp - 0x4;
                                                                                                                                    decomp_var_8c = 0x7;
                                                                                                                                    ecx = decomp_var_8c;
                                                                                                                                    esp = esp + 0x4;
                                                                                                                                    temp_0 = 0x20;
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            eax = eax - 0x2;
                                                                                                                            if (eax == 0x0) {
                                                                                                                                    var_68 = var_68 | 0xffffffff;
                                                                                                                                    ecx = 0x7;
                                                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                                                    temp_0 = 0x20;
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            edx = ecx;
                                                                                                                            temp_1 = 0x0;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                                            edx = edx - 0x1;
                                                                                                                            ecx = 0xa;
                                                                                                                            if (0xa != 0xa) {
                                                                                                                                    temp_0 = 0x20;
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_1 = 0x0;
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (ecx != 0xa) {
                                                                                                                            temp_0 = 0x20;
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_1 = 0x0;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            var_60 = 0x1;
                                                                                                            ecx = 0x0;
                                                                                                            temp_1 = 0x8;
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    var_60 = 0x1;
                                                                                                    while (eax == 0x30) {
                                                                                                            eax = *(int8_t *)edx;
                                                                                                            edx = edx + 0x1;
                                                                                                    }
                                                                                                    eax = eax - 0x31;
                                                                                                    if (eax <= 0x8) {
                                                                                                            esp = esp - 0x4;
                                                                                                            decomp_var_8c = 0x9;
                                                                                                            ecx = decomp_var_8c;
                                                                                                            esp = esp + 0x4;
                                                                                                            edx = edx - 0x1;
                                                                                                            temp_0 = 0x20;
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = eax - 0x31;
                                                                                            bool_598 = ecx != 0x8;
                                                                                            if (ecx <= 0x8) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_8c = 0x9;
                                                                                                    ecx = decomp_var_8c;
                                                                                                    esp = esp + 0x4;
                                                                                                    edx = edx - 0x1;
                                                                                                    temp_0 = 0x20;
                                                                                                    continue;
                                                                                            }
                                                                                            if (!bool_598) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_8c = 0x8;
                                                                                                    ecx = decomp_var_8c;
                                                                                                    esp = esp + 0x4;
                                                                                                    temp_0 = 0x20;
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x5;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    var_54 = edx - 0x2;
                                                                                    ecx = eax - 0x31;
                                                                                    if (ecx <= 0x8) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_8c = 0x9;
                                                                                            ecx = decomp_var_8c;
                                                                                            esp = esp + 0x4;
                                                                                            edx = edx - 0x1;
                                                                                            temp_0 = 0x20;
                                                                                            continue;
                                                                                    }
                                                                                    eax = sign_extend_32(eax) - 0x2b;
                                                                                    if (eax == 0x0) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_8c = 0x7;
                                                                                            ecx = decomp_var_8c;
                                                                                            esp = esp + 0x4;
                                                                                            temp_0 = 0x20;
                                                                                            continue;
                                                                                    }
                                                                                    eax = eax - 0x2;
                                                                                    bool_565 = eax != 0x0;
                                                                                    if (eax == 0x0) {
                                                                                            var_68 = var_68 | 0xffffffff;
                                                                                            ecx = 0x7;
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            temp_0 = 0x20;
                                                                                            continue;
                                                                                    }
                                                                                    eax = eax - 0x3;
                                                                                    if (!bool_565) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_8c = 0x8;
                                                                                            ecx = decomp_var_8c;
                                                                                            esp = esp + 0x4;
                                                                                            temp_0 = 0x20;
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x5;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = eax - 0x30;
                                                                            var_5C = 0x1;
                                                                            if (eax <= 0x9) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_8c = 0x4;
                                                                                    ecx = decomp_var_8c;
                                                                                    esp = esp + 0x4;
                                                                                    edx = edx - 0x1;
                                                                                    temp_0 = 0x20;
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x5;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    var_58 = 0x1;
                                                                    var_5C = 0x1;
                                                                    if (var_4C == 0x0) {
                                                                            while (eax == 0x30) {
                                                                                    var_50 = var_50 - 0x1;
                                                                                    eax = *(int8_t *)edx;
                                                                                    edx = edx + 0x1;
                                                                            }
                                                                    }
                                                                    if (eax < 0x30) {
                                                                            if (eax == 0x2b) {
                                                                                    edx = edx - 0x1;
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_8c = 0xb;
                                                                                    ecx = decomp_var_8c;
                                                                                    esp = esp + 0x4;
                                                                                    temp_0 = 0x20;
                                                                                    continue;
                                                                            }
                                                                            if (eax == 0x2d) {
                                                                                    edx = edx - 0x1;
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_8c = 0xb;
                                                                                    ecx = decomp_var_8c;
                                                                                    esp = esp + 0x4;
                                                                                    temp_0 = 0x20;
                                                                                    continue;
                                                                            }
                                                                            if (eax > 0x43) {
                                                                                    if (eax <= 0x45) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_8c = 0x6;
                                                                                            ecx = decomp_var_8c;
                                                                                            esp = esp + 0x4;
                                                                                            temp_0 = 0x20;
                                                                                            continue;
                                                                                    }
                                                                                    if (eax > 0x63) {
                                                                                            if (eax <= 0x65) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_8c = 0x6;
                                                                                                    ecx = decomp_var_8c;
                                                                                                    esp = esp + 0x4;
                                                                                                    temp_0 = 0x20;
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x4;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax <= 0x39) {
                                                                                    if (var_4C < 0x19) {
                                                                                            var_4C = var_4C + 0x1;
                                                                                            *(int8_t *)edi = eax - 0x30;
                                                                                            edi = edi + 0x1;
                                                                                            var_50 = var_50 - 0x1;
                                                                                    }
                                                                                    eax = *(int8_t *)edx;
                                                                                    edx = edx + 0x1;
                                                                                    temp_0 = 0xd;
                                                                                    continue;
                                                                            }
                                                                            if (eax == 0x2b) {
                                                                                    edx = edx - 0x1;
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_8c = 0xb;
                                                                                    ecx = decomp_var_8c;
                                                                                    esp = esp + 0x4;
                                                                                    temp_0 = 0x20;
                                                                                    continue;
                                                                            }
                                                                            if (eax == 0x2d) {
                                                                                    edx = edx - 0x1;
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_8c = 0xb;
                                                                                    ecx = decomp_var_8c;
                                                                                    esp = esp + 0x4;
                                                                                    temp_0 = 0x20;
                                                                                    continue;
                                                                            }
                                                                            if (eax > 0x43) {
                                                                                    if (eax <= 0x45) {
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_8c = 0x6;
                                                                                            ecx = decomp_var_8c;
                                                                                            esp = esp + 0x4;
                                                                                            temp_0 = 0x20;
                                                                                            continue;
                                                                                    }
                                                                                    if (eax > 0x63) {
                                                                                            if (eax <= 0x65) {
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_8c = 0x6;
                                                                                                    ecx = decomp_var_8c;
                                                                                                    esp = esp + 0x4;
                                                                                                    temp_0 = 0x20;
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x4;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x3;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            var_58 = 0x1;
                                                            while (eax >= 0x30) {
                                                                    if (eax > 0x39) {
                                                                            break;
                                                                    }
                                                                    if (var_4C < 0x19) {
                                                                            var_4C = var_4C + 0x1;
                                                                            *(int8_t *)edi = eax - 0x30;
                                                                            edi = edi + 0x1;
                                                                    }
                                                                    else {
                                                                            var_50 = var_50 + 0x1;
                                                                    }
                                                                    eax = *(int8_t *)edx;
                                                                    edx = edx + 0x1;
                                                            }
                                                            ecx = *arg_1c;
                                                            ecx = ecx[0x2f];
                                                            ecx = *ecx;
                                                            if (eax == *(int8_t *)ecx) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_8c = 0x4;
                                                                    ecx = decomp_var_8c;
                                                                    esp = esp + 0x4;
                                                                    temp_0 = 0x20;
                                                                    continue;
                                                            }
                                                            if (eax == 0x2b) {
                                                                    edx = edx - 0x1;
                                                                    esp = esp - 0x4;
                                                                    decomp_var_8c = 0xb;
                                                                    ecx = decomp_var_8c;
                                                                    esp = esp + 0x4;
                                                                    temp_0 = 0x20;
                                                                    continue;
                                                            }
                                                            if (eax == 0x2d) {
                                                                    edx = edx - 0x1;
                                                                    esp = esp - 0x4;
                                                                    decomp_var_8c = 0xb;
                                                                    ecx = decomp_var_8c;
                                                                    esp = esp + 0x4;
                                                                    temp_0 = 0x20;
                                                                    continue;
                                                            }
                                                            if (eax > 0x43) {
                                                                    if (eax <= 0x45) {
                                                                            esp = esp - 0x4;
                                                                            decomp_var_8c = 0x6;
                                                                            ecx = decomp_var_8c;
                                                                            esp = esp + 0x4;
                                                                            temp_0 = 0x20;
                                                                            continue;
                                                                    }
                                                                    if (eax > 0x63) {
                                                                            if (eax <= 0x65) {
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_8c = 0x6;
                                                                                    ecx = decomp_var_8c;
                                                                                    esp = esp + 0x4;
                                                                                    temp_0 = 0x20;
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x4;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_1 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (eax <= 0x39) {
                                                            esp = esp - 0x4;
                                                            decomp_var_8c = 0x3;
                                                            ecx = decomp_var_8c;
                                                            esp = esp + 0x4;
                                                            edx = edx - 0x1;
                                                            temp_0 = 0x20;
                                                            continue;
                                                    }
                                                    ecx = *arg_1c;
                                                    ecx = ecx[0x2f];
                                                    ecx = *ecx;
                                                    if (eax == *(int8_t *)ecx) {
                                                            esp = esp - 0x4;
                                                            decomp_var_8c = 0x5;
                                                            ecx = decomp_var_8c;
                                                            esp = esp + 0x4;
                                                            temp_0 = 0x20;
                                                            continue;
                                                    }
                                                    if (eax == 0x30) {
                                                            ecx = 0x1;
                                                            temp_0 = 0x20;
                                                            continue;
                                                    }
                                                    temp_1 = 0x6;
                                                    break;
                                            }
                                    }
                                    else {
                                            var_58 = 0x1;
                                            if (eax <= 0x39) {
                                                    esp = esp - 0x4;
                                                    decomp_var_8c = 0x3;
                                                    ecx = decomp_var_8c;
                                                    esp = esp + 0x4;
                                                    edx = edx - 0x1;
                                                    temp_0 = 0x20;
                                                    continue;
                                            }
                                            ecx = *arg_1c;
                                            ecx = ecx[0x2f];
                                            ecx = *ecx;
                                            if (eax == *(int8_t *)ecx) {
                                                    esp = esp - 0x4;
                                                    decomp_var_8c = 0x4;
                                                    ecx = decomp_var_8c;
                                                    esp = esp + 0x4;
                                                    temp_0 = 0x20;
                                                    continue;
                                            }
                                            if (eax == 0x2b) {
                                                    edx = edx - 0x1;
                                                    esp = esp - 0x4;
                                                    decomp_var_8c = 0xb;
                                                    ecx = decomp_var_8c;
                                                    esp = esp + 0x4;
                                                    temp_0 = 0x20;
                                                    continue;
                                            }
                                            if (eax == 0x2d) {
                                                    edx = edx - 0x1;
                                                    esp = esp - 0x4;
                                                    decomp_var_8c = 0xb;
                                                    ecx = decomp_var_8c;
                                                    esp = esp + 0x4;
                                                    temp_0 = 0x20;
                                                    continue;
                                            }
                                            if (eax == 0x30) {
                                                    ecx = 0x1;
                                                    temp_0 = 0x20;
                                                    continue;
                                            }
                                            if (eax > 0x43) {
                                                    if (eax <= 0x45) {
                                                            esp = esp - 0x4;
                                                            decomp_var_8c = 0x6;
                                                            ecx = decomp_var_8c;
                                                            esp = esp + 0x4;
                                                            temp_0 = 0x20;
                                                            continue;
                                                    }
                                                    if (eax > 0x63) {
                                                            if (eax <= 0x65) {
                                                                    esp = esp - 0x4;
                                                                    decomp_var_8c = 0x6;
                                                                    ecx = decomp_var_8c;
                                                                    esp = esp + 0x4;
                                                                    temp_0 = 0x20;
                                                                    continue;
                                                            }
                                                            temp_1 = 0x4;
                                                            break;
                                                    }
                                                    else {
                                                            temp_1 = 0x3;
                                                            break;
                                                    }
                                            }
                                            else {
                                                    temp_1 = 0x2;
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (eax <= 0x39) {
                                            esp = esp - 0x4;
                                            decomp_var_8c = 0x3;
                                            ecx = decomp_var_8c;
                                            esp = esp + 0x4;
                                            edx = edx - 0x1;
                                            temp_0 = 0x20;
                                            continue;
                                    }
                                    ecx = *arg_1c;
                                    ecx = ecx[0x2f];
                                    ecx = *ecx;
                                    if (eax == *(int8_t *)ecx) {
                                            esp = esp - 0x4;
                                            decomp_var_8c = 0x5;
                                            ecx = decomp_var_8c;
                                            esp = esp + 0x4;
                                            temp_0 = 0x20;
                                            continue;
                                    }
                                    eax = sign_extend_32(eax) - 0x2b;
                                    if (eax == 0x0) {
                                            var_74 = var_74 & 0x0;
                                            ecx = 0x2;
                                            esp = (esp - 0x4) + 0x4;
                                            temp_0 = 0x20;
                                            continue;
                                    }
                                    eax = eax - 0x2;
                                    if (eax == 0x0) {
                                            ecx = 0x2;
                                            esp = (esp - 0x4) + 0x4;
                                            var_74 = 0x8000;
                                            temp_0 = 0x20;
                                            continue;
                                    }
                                    eax = eax - 0x3;
                                    if (eax == 0x0) {
                                            ecx = 0x1;
                                            temp_0 = 0x20;
                                            continue;
                                    }
                                    temp_1 = 0x7;
                                    break;
                            }
                    }
                    else {
                            if (ecx != 0xa) {
                                    temp_0 = 0x20;
                                    continue;
                            }
                            temp_1 = 0x0;
                            break;
                    }
            }
            else {
                    if (eax < 0x30) {
                            if (eax == 0x2b) {
                                    edx = edx - 0x1;
                                    esp = esp - 0x4;
                                    decomp_var_8c = 0xb;
                                    ecx = decomp_var_8c;
                                    esp = esp + 0x4;
                                    temp_0 = 0x20;
                                    continue;
                            }
                            if (eax == 0x2d) {
                                    edx = edx - 0x1;
                                    esp = esp - 0x4;
                                    decomp_var_8c = 0xb;
                                    ecx = decomp_var_8c;
                                    esp = esp + 0x4;
                                    temp_0 = 0x20;
                                    continue;
                            }
                            if (eax > 0x43) {
                                    if (eax <= 0x45) {
                                            esp = esp - 0x4;
                                            decomp_var_8c = 0x6;
                                            ecx = decomp_var_8c;
                                            esp = esp + 0x4;
                                            temp_0 = 0x20;
                                            continue;
                                    }
                                    if (eax > 0x63) {
                                            if (eax <= 0x65) {
                                                    esp = esp - 0x4;
                                                    decomp_var_8c = 0x6;
                                                    ecx = decomp_var_8c;
                                                    esp = esp + 0x4;
                                                    temp_0 = 0x20;
                                                    continue;
                                            }
                                            temp_1 = 0x4;
                                            break;
                                    }
                                    else {
                                            temp_1 = 0x3;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x2;
                                    break;
                            }
                    }
                    else {
                            if (eax <= 0x39) {
                                    if (var_4C < 0x19) {
                                            var_4C = var_4C + 0x1;
                                            *(int8_t *)edi = eax - 0x30;
                                            edi = edi + 0x1;
                                            var_50 = var_50 - 0x1;
                                    }
                                    eax = *(int8_t *)edx;
                                    edx = edx + 0x1;
                                    temp_0 = 0xd;
                                    continue;
                            }
                            if (eax == 0x2b) {
                                    edx = edx - 0x1;
                                    esp = esp - 0x4;
                                    decomp_var_8c = 0xb;
                                    ecx = decomp_var_8c;
                                    esp = esp + 0x4;
                                    temp_0 = 0x20;
                                    continue;
                            }
                            if (eax == 0x2d) {
                                    edx = edx - 0x1;
                                    esp = esp - 0x4;
                                    decomp_var_8c = 0xb;
                                    ecx = decomp_var_8c;
                                    esp = esp + 0x4;
                                    temp_0 = 0x20;
                                    continue;
                            }
                            if (eax > 0x43) {
                                    if (eax <= 0x45) {
                                            esp = esp - 0x4;
                                            decomp_var_8c = 0x6;
                                            ecx = decomp_var_8c;
                                            esp = esp + 0x4;
                                            temp_0 = 0x20;
                                            continue;
                                    }
                                    if (eax > 0x63) {
                                            if (eax <= 0x65) {
                                                    esp = esp - 0x4;
                                                    decomp_var_8c = 0x6;
                                                    ecx = decomp_var_8c;
                                                    esp = esp + 0x4;
                                                    temp_0 = 0x20;
                                                    continue;
                                            }
                                            temp_1 = 0x4;
                                            break;
                                    }
                                    else {
                                            temp_1 = 0x3;
                                            break;
                                    }
                            }
                            else {
                                    temp_1 = 0x2;
                                    break;
                            }
                    }
            }
    }
    if (temp_1 == 0x0) goto loc_490c32;
    goto .l129;

loc_4909f2:
    *sub_47d812() = 0x16;
    sub_47a924();
    esp = (esp - 0x14) + 0x14;
    goto loc_49102b;

loc_490c32:
    *var_70 = edx;
    if (var_58 == 0x0) goto loc_490fe6;
    goto loc_490c41;

.l129:
    if (temp_1 == 0x1 || temp_1 == 0x2 || temp_1 == 0x3 || temp_1 == 0x4) goto loc_490c07;
    goto .l133;

loc_49102b:
    eax = sub_47ad69();
    return eax;

loc_490fe6:
    var_6C = 0x4;
    goto loc_49100d;

loc_490c41:
    esp = (esp - 0x4) + 0x4;
    if (var_4C > 0x18) {
            edi = edi - 0x1;
            var_50 = var_50 + 0x1;
            var_4C = 0x18;
    }
    if (var_4C <= 0x0) goto loc_49100d;
    goto loc_490c63;

loc_490c07:
    edx = edx - 0x1;
    goto loc_490c32;

.l133:
    if (temp_1 == 0x5 || temp_1 == 0x6) goto loc_490b16;
    goto .l135;

loc_49100d:
    ecx = 0x0;
    eax = 0x0;
    edx = 0x0;
    esi = 0x0;
    goto loc_491015;

loc_490c63:
    while (true) {
            edi = edi - 0x1;
            if (*(int8_t *)edi != 0x0) {
                    break;
            }
            var_4C = var_4C - 0x1;
            var_50 = var_50 + 0x1;
    }
    eax = sub_492db1(&var_20, var_4C, &var_3C);
    eax = var_64;
    esp = (esp - 0xc) + 0xc;
    if (var_68 < 0x0) {
            eax = -eax;
    }
    eax = eax + var_50;
    if (var_60 == 0x0) {
            eax = eax + arg_10;
    }
    if (var_5C == 0x0) {
            eax = eax - arg_14;
    }
    if (eax > 0x1450) goto loc_490fef;
    goto loc_490d01;

loc_490b16:
    edx = var_54;
    goto loc_490c32;

.l135:
    if (temp_1 != 0x7) {
            while (true) {
                    if (eax < 0x30) {
                            temp_2 = 0x0;
                            break;
                    }
                    else {
                            if (eax <= 0x39) {
                                    ecx = ecx * 0xa + (sign_extend_32(eax) - 0x30);
                                    if (ecx <= 0x1450) {
                                            eax = *(int8_t *)edx;
                                            edx = edx + 0x1;
                                            continue;
                                    }
                                    ecx = 0x1451;
                                    temp_2 = 0x1;
                                    break;
                            }
                            else {
                                    temp_2 = 0x0;
                                    break;
                            }
                    }
            }
            var_64 = ecx;
            while (eax >= 0x30) {
                    if (eax > 0x39) {
                            break;
                    }
                    eax = *(int8_t *)edx;
                    edx = edx + 0x1;
            }
    }
    goto loc_490c07;

loc_491015:
    *(int16_t *)var_7C = ecx;
    var_7C[0x5] = eax | var_74;
    *(var_7C + 0x2) = esi;
    *(var_7C + 0x6) = edx;
    goto loc_49102b;

loc_490fef:
    esi = 0x0;
    eax = 0x7fff;
    edx = 0x80000000;
    ecx = 0x0;
    var_6C = 0x2;
    goto loc_491015;

loc_490d01:
    if (eax < 0xffffebb0) goto loc_491006;
    goto loc_490d0c;

loc_491006:
    var_6C = 0x1;
    goto loc_49100d;

loc_490d0c:
    esi = 0x4ca160;
    bool_6 = eax >= 0x0;
    var_54 = eax;
    if (eax == 0x0) goto loc_490fd4;
    goto loc_490d1f;

loc_490fd4:
    ecx = var_3C & 0xffff;
    esi = var_3A;
    edx = var_36;
    eax = var_34 >> 0x10;
    goto loc_491015;

loc_490d1f:
    if (!bool_6) {
            var_54 = -eax;
            esi = 0x4ca2c0;
    }
    if (arg_c == 0x0) {
            var_3C = 0x0;
    }
    if (var_54 == 0x0) goto loc_490fd4;

loc_490d40:
    eax = var_54;
    var_54 = SAR(var_54, 0x3);
    esi = esi + 0x54;
    eax = eax & 0x7;
    var_4C = esi;
    if (eax == 0x0) goto .l6;
    goto loc_490d58;

.l6:
    if (var_54 != 0x0) {
            continue;
    }
    break;

loc_490d58:
    ebx = eax * 0xc + esi;
    bool_163 = true;
    bool_162 = true;
    bool_161 = true;
    var_70 = ebx;
    if (*(int16_t *)ebx >= 0x8000) {
            var_48 = *ebx;
            var_48 = *ebx;
            var_48 = *ebx;
            var_46 = var_46 - 0x1;
            esi = var_4C;
            ebx = &var_48;
            var_70 = ebx;
    }
    edx = ebx[0x5] & 0xffff;
    var_50 = 0x0;
    var_2C = 0x0;
    var_28 = 0x0;
    var_24 = 0x0;
    eax = edx ^ var_32;
    ecx = var_32 & 0x7fff;
    edx = edx & 0x7fff;
    eax = eax & 0x8000;
    edi = edx + ecx & 0xffff;
    if (ecx >= 0x7fff) goto loc_490fb0;
    goto loc_490db5;

loc_490fb0:
    var_38 = var_38 & 0x0;
    eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    var_3C = var_3C & 0x0;
    var_34 = eax;
    if (var_54 != 0x0) {
            continue;
    }
    break;

loc_490db5:
    if (edx >= 0x7fff) goto .l43;
    goto loc_490dc0;

.l43:
    var_38 = var_38 & 0x0;
    eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    var_3C = var_3C & 0x0;
    var_34 = eax;
    if (var_54 != 0x0) {
            continue;
    }
    break;

loc_490dc0:
    if (edi > 0xbffd) goto .l16;
    goto loc_490dcb;

.l16:
    var_38 = var_38 & 0x0;
    eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
    var_3C = var_3C & 0x0;
    var_34 = eax;
    if (var_54 != 0x0) {
            continue;
    }
    break;

loc_490dcb:
    if (edi > 0x3fbf) goto loc_490ddf;
    goto loc_490dd2;

loc_490ddf:
    if (ecx != 0x0) goto .l21;
    goto loc_490de4;

loc_490dd2:
    var_38 = 0x0;
    var_3C = 0x0;
    var_34 = 0x0;
    if (var_54 != 0x0) {
            continue;
    }
    break;

.l21:
    if (edx != 0x0) goto .l8;
    goto .l37;

loc_490de4:
    edi = edi + 0x1;
    if ((var_34 & 0x7fffffff) != 0x0) goto .l9;
    goto loc_490dee;

.l8:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l97;

.l37:
    edi = edi + 0x1;
    if ((ebx[0x2] & 0x7fffffff) != 0x0) goto .l41;
    goto .l35;

.l9:
    if (edx != 0x0) goto .l11;
    goto .l22;

loc_490dee:
    if (var_38 != 0x0) goto .l10;
    goto loc_490df4;

.l97:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l95;
    goto .l96;

.l41:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l118;

.l35:
    if (ebx[0x1] != 0x0) goto .l27;
    goto .l46;

.l11:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l62;

.l22:
    edi = edi + 0x1;
    if ((ebx[0x2] & 0x7fffffff) != 0x0) goto .l7;
    goto .l31;

.l10:
    if (edx != 0x0) goto .l28;
    goto loc_490e0a;

loc_490df4:
    if (var_3C != 0x0) goto loc_490e03;
    goto loc_490dfa;

.l95:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l96:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l99;

.l118:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l115;
    goto .l117;

.l27:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l57;

.l46:
    if (*ebx != 0x0) goto .l13;
    goto .l38;

.l62:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l61;
    goto .l60;

.l7:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l76;

.l31:
    if (ebx[0x1] != 0x0) goto .l24;
    goto .l39;

.l28:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l82;

loc_490e0a:
    edi = edi + 0x1;
    if ((ebx[0x2] & 0x7fffffff) != 0x0) goto .l19;
    goto loc_490e14;

loc_490e03:
    if (edx != 0x0) goto .l4;
    goto .l49;

loc_490dfa:
    var_32 = var_32 & ecx;
    if (var_54 != 0x0) {
            continue;
    }
    break;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l99:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l115:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l117:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l119;

.l57:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l56;
    goto .l58;

.l13:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto loc_490e38;

.l38:
    var_34 = 0x0;
    var_38 = 0x0;
    var_3C = 0x0;
    if (var_54 != 0x0) {
            continue;
    }
    break;

.l61:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l60:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l64;

.l76:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l78;
    goto .l75;

.l24:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l65;

.l39:
    if (*ebx != 0x0) goto loc_490e2b;
    goto .l17;

.l82:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l81;
    goto .l80;

.l19:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l112;

loc_490e14:
    if (ebx[0x1] != 0x0) goto .l12;
    goto .l29;

.l4:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l100;

.l49:
    edi = edi + 0x1;
    if ((ebx[0x2] & 0x7fffffff) != 0x0) goto .l40;
    goto .l26;
    ebx = var_70;
    goto .l95;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l119:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l56:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l58:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l59;

loc_490e38:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto loc_490e9c;
    goto loc_490e47;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l64:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l78:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l75:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l79;

.l65:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l68;
    goto .l66;

loc_490e2b:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l72;

.l17:
    var_34 = 0x0;
    var_38 = 0x0;
    var_3C = 0x0;
    if (var_54 != 0x0) {
            continue;
    }
    break;

.l81:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l80:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l84;

.l112:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l110;
    goto .l113;

.l12:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l88;

.l29:
    if (*ebx != 0x0) goto .l25;
    goto loc_490e1d;

.l100:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l101;
    goto .l102;

.l40:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l50;

.l26:
    if (ebx[0x1] != 0x0) goto .l14;
    goto loc_490e19;
    ebx = var_70;
    goto .l115;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l59:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

loc_490e9c:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

loc_490e47:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto loc_490e54;
    ebx = var_70;
    goto .l61;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l79:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l68:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l66:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l69;

.l72:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l73;
    goto .l71;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l84:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l110:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l113:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l114;

.l88:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l86;
    goto .l85;

.l25:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l120;

loc_490e1d:
    var_34 = 0x0;
    var_38 = 0x0;
    var_3C = 0x0;
    if (var_54 != 0x0) {
            continue;
    }
    break;

.l101:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l102:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l104;

.l50:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l53;
    goto .l52;

.l14:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l92;

loc_490e19:
    if (*ebx != 0x0) goto .l45;
    goto .l30;
    ebx = var_70;
    goto .l56;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

loc_490e54:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;
    ebx = var_70;
    goto .l78;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l69:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l73:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l71:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l74;
    ebx = var_70;
    goto .l81;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l114:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l86:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l85:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l89;

.l120:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l123;
    goto .l121;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l104:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l53:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l52:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l54;

.l92:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l93;
    goto .l91;

.l45:
    var_68 = var_68 & 0x0;
    esi = &var_28;
    var_58 = 0x5;
    goto .l106;

.l30:
    var_34 = 0x0;
    var_38 = 0x0;
    var_3C = 0x0;
    if (var_54 != 0x0) {
            continue;
    }
    break;
    ebx = var_70;
    goto loc_490e9c;
    ebx = var_70;
    goto .l68;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l74:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;
    ebx = var_70;
    goto .l110;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l89:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l123:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l121:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l124;
    ebx = var_70;
    goto .l101;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l54:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l93:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l91:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l94;

.l106:
    ecx = var_68 + var_68;
    var_64 = var_58;
    if (var_58 <= 0x0) goto .l108;
    goto .l105;
    ebx = var_70;
    goto .l73;
    ebx = var_70;
    goto .l86;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l124:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;
    ebx = var_70;
    goto .l53;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l94:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;

.l108:
    esi = esi + 0x2;
    var_68 = var_68 + 0x1;
    var_58 = var_58 - 0x1;
    if (var_58 > 0x0) {
            continue;
    }
    break;

.l105:
    var_5C = ebp + (ecx - 0x3c);
    var_60 = ebx + 0x8;
    goto .l109;
    ebx = var_70;
    goto .l123;
    ebx = var_70;
    goto .l93;
    edi = edi + 0xc002;
    if (edi > 0x0) {
            while ((var_24 & 0x80000000) == 0x0) {
                    ecx = var_2C;
                    var_2C = var_2C << 0x1;
                    esi = var_28 + var_28 | ecx >> 0x1f;
                    ecx = var_24 + var_24 | var_28 >> 0x1f;
                    edi = edi + 0xffff;
                    var_28 = esi;
                    var_24 = ecx;
                    if (edi <= 0x0) {
                            break;
                    }
            }
            if (edi <= 0x0) {
                    edi = edi + 0xffff;
                    if (edi < 0x0) {
                            esi = -edi & 0xffff;
                            edi = edi + esi;
                            do {
                                    if ((var_2C & 0x1) != 0x0) {
                                            var_50 = var_50 + 0x1;
                                    }
                                    ecx = var_24;
                                    var_24 = var_24 >> 0x1;
                                    ebx = var_28 >> 0x1 | ecx << 0x1f;
                                    ecx = var_2C >> 0x1 | var_28 << 0x1f;
                                    esi = esi - 0x1;
                                    var_28 = ebx;
                                    var_2C = ecx;
                            } while (esi != 0x0);
                            if (var_50 != 0x0) {
                                    var_2C = var_2C | 0x1;
                            }
                    }
            }
    }
    else {
            edi = edi + 0xffff;
            if (edi < 0x0) {
                    esi = -edi & 0xffff;
                    edi = edi + esi;
                    do {
                            if ((var_2C & 0x1) != 0x0) {
                                    var_50 = var_50 + 0x1;
                            }
                            ecx = var_24;
                            var_24 = var_24 >> 0x1;
                            ebx = var_28 >> 0x1 | ecx << 0x1f;
                            ecx = var_2C >> 0x1 | var_28 << 0x1f;
                            esi = esi - 0x1;
                            var_28 = ebx;
                            var_2C = ecx;
                    } while (esi != 0x0);
                    if (var_50 != 0x0) {
                            var_2C = var_2C | 0x1;
                    }
            }
    }
    if (var_2C <= 0x8000) {
            if ((var_2C & 0x1ffff) == 0x18000) {
                    if (var_2A == 0xffffffff) {
                            var_2A = var_2A & 0x0;
                            if (var_26 == 0xffffffff) {
                                    var_26 = var_26 & 0x0;
                                    if (var_22 == 0xffff) {
                                            var_22 = 0x8000;
                                            edi = edi + 0x1;
                                    }
                                    else {
                                            var_22 = var_22 + 0x1;
                                    }
                            }
                            else {
                                    var_26 = var_26 + 0x1;
                            }
                    }
                    else {
                            var_2A = var_2A + 0x1;
                    }
            }
    }
    else {
            if (var_2A == 0xffffffff) {
                    var_2A = var_2A & 0x0;
                    if (var_26 == 0xffffffff) {
                            var_26 = var_26 & 0x0;
                            if (var_22 == 0xffff) {
                                    var_22 = 0x8000;
                                    edi = edi + 0x1;
                            }
                            else {
                                    var_22 = var_22 + 0x1;
                            }
                    }
                    else {
                            var_26 = var_26 + 0x1;
                    }
            }
            else {
                    var_2A = var_2A + 0x1;
            }
    }
    esi = var_4C;
    if (edi < 0x7fff) {
            var_3C = var_2A;
            var_3A = var_28;
            var_36 = var_24;
            var_32 = edi | eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    else {
            var_38 = var_38 & 0x0;
            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0x80000000) + 0x7fff8000;
            var_3C = var_3C & 0x0;
            var_34 = eax;
            if (var_54 != 0x0) {
                    continue;
            }
            break;
    }
    goto loc_490fd4;

.l109:
    edx = *(int16_t *)var_5C & 0xffff;
    ecx = *(int16_t *)var_60 & 0xffff;
    var_78 = var_78 & 0x0;
    ecx = ecx * edx;
    edx = *(esi - 0x4);
    ebx = edx + ecx;
    if (ebx < edx || ebx < ecx) {
            var_78 = 0x1;
    }
    *(esi - 0x4) = ebx;
    if (var_78 != 0x0) {
            *(int16_t *)esi = *(int16_t *)esi + 0x1;
    }
    var_5C = var_5C + 0x2;
    var_60 = var_60 - 0x2;
    var_64 = var_64 - 0x1;
    if (var_64 > 0x0) {
            continue;
    }
    break;
    ebx = var_70;
    goto .l108;
}
