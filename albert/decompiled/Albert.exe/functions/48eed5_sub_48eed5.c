// sub_48eed5 @ 0x48eed5
// hopper name: sub_48eed5
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48eed5() {
    decomp_var_18 = esi;
    esp = esp - 0x8;
    sub_47aea2(arg_8);
    edx = arg_0;
    if (edx == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
            if (var_8 != 0x0) {
                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
            }
            eax = 0x7fffffff;
    }
    else {
            esp = esp - 0x4;
            decomp_var_1c = ebx;
            ebx = arg_4;
            if (ebx == 0x0) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    if (var_8 != 0x0) {
                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                    }
                    eax = 0x7fffffff;
            }
            else {
                    eax = var_10;
                    if (eax[0x2] == 0x0) {
                            eax = sub_48fbb3(edx, ebx, &var_14);
                            esp = (esp - 0xc) + 0xc;
                            if (var_8 != 0x0) {
                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_20 = edi;
                            while (true) {
                                    ecx = *(int8_t *)edx & 0xff;
                                    ecx = ecx & 0xffff;
                                    edx = edx + 0x1;
                                    arg_0 = edx;
                                    if ((*(int8_t *)((ecx & 0xff) + eax + 0x1d) & 0x4) != 0x0) {
                                            if (*(int8_t *)edx == 0x0) {
                                                    ecx = *(int8_t *)ebx & 0xff;
                                                    ecx = ecx & 0xffff;
                                                    ebx = ebx + 0x1;
                                                    if ((*(int8_t *)((ecx & 0xff) + eax + 0x1d) & 0x4) != 0x0) {
                                                            if (*(int8_t *)ebx == 0x0) {
                                                                    bool_80 = true;
                                                                    if (0x0 == 0x0) {
                                                                            if (0x0 != 0x0) {
                                                                                    edx = arg_0;
                                                                                    continue;
                                                                            }
                                                                            if (var_8 != 0x0) {
                                                                                    eax = var_C;
                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                    temp_0 = 0x3;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x3;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    temp_0 = 0x1;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x0;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_482d50(&var_14, eax[0x3], 0x200, ebx - 0x1, 0x2, &var_4, 0x2, eax[0x1], 0x1);
                                                                    esp = (esp - 0x24) + 0x24;
                                                                    if (eax == 0x1) {
                                                                            eax = var_4 & 0xff;
                                                                            ecx = eax & 0xffff;
                                                                            eax = var_10;
                                                                            ebx = ebx + 0x1;
                                                                            bool_51 = true;
                                                                            if (ecx == 0x0) {
                                                                                    if (0x0 != 0x0) {
                                                                                            edx = arg_0;
                                                                                            continue;
                                                                                    }
                                                                                    if (var_8 != 0x0) {
                                                                                            eax = var_C;
                                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                    if (var_8 != 0x0) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x0;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax == 0x2) {
                                                                                    eax = ((var_4 & 0xff) << 0x8) + (var_3 & 0xff);
                                                                                    ecx = eax & 0xffff;
                                                                                    eax = var_10;
                                                                                    ebx = ebx + 0x1;
                                                                                    bool_42 = true;
                                                                                    if (ecx == 0x0) {
                                                                                            if (0x0 != 0x0) {
                                                                                                    edx = arg_0;
                                                                                                    continue;
                                                                                            }
                                                                                            if (var_8 != 0x0) {
                                                                                                    eax = var_C;
                                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                                    temp_0 = 0x3;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x3;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                            if (var_8 != 0x0) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                                    temp_0 = 0x1;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x0;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            edx = ecx & 0xffff;
                                                            ecx = edx + eax;
                                                            if ((ecx[0x1d] & 0x10) != 0x0) {
                                                                    ecx = ecx[0x11d] & 0xff;
                                                                    ecx = ecx & 0xffff;
                                                            }
                                                            else {
                                                                    ecx = edx & 0xffff;
                                                            }
                                                            bool_11 = true;
                                                            if (ecx == 0x0) {
                                                                    if (0x0 != 0x0) {
                                                                            edx = arg_0;
                                                                            continue;
                                                                    }
                                                                    if (var_8 != 0x0) {
                                                                            eax = var_C;
                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                            temp_0 = 0x3;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x3;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                    if (var_8 != 0x0) {
                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            temp_0 = 0x1;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x0;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = sub_482d50(&var_14, eax[0x3], 0x200, edx - 0x1, 0x2, &var_4, 0x2, eax[0x1], 0x1);
                                                    esp = (esp - 0x24) + 0x24;
                                                    if (eax == 0x1) {
                                                            eax = var_4 & 0xff;
                                                            arg_0 = arg_0 + 0x1;
                                                            esi = eax & 0xffff;
                                                            eax = var_10;
                                                            ecx = *(int8_t *)ebx & 0xff;
                                                            ecx = ecx & 0xffff;
                                                            ebx = ebx + 0x1;
                                                            if ((*(int8_t *)((ecx & 0xff) + eax + 0x1d) & 0x4) != 0x0) {
                                                                    if (*(int8_t *)ebx == 0x0) {
                                                                            bool_101 = true;
                                                                            if (0x0 == esi) {
                                                                                    if (esi != 0x0) {
                                                                                            edx = arg_0;
                                                                                            continue;
                                                                                    }
                                                                                    if (var_8 != 0x0) {
                                                                                            eax = var_C;
                                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                    if (var_8 != 0x0) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x0;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_482d50(&var_14, eax[0x3], 0x200, ebx - 0x1, 0x2, &var_4, 0x2, eax[0x1], 0x1);
                                                                            esp = (esp - 0x24) + 0x24;
                                                                            if (eax == 0x1) {
                                                                                    eax = var_4 & 0xff;
                                                                                    ecx = eax & 0xffff;
                                                                                    eax = var_10;
                                                                                    ebx = ebx + 0x1;
                                                                                    bool_84 = true;
                                                                                    if (ecx == esi) {
                                                                                            if (esi != 0x0) {
                                                                                                    edx = arg_0;
                                                                                                    continue;
                                                                                            }
                                                                                            if (var_8 != 0x0) {
                                                                                                    eax = var_C;
                                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                                    temp_0 = 0x3;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x3;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                            if (var_8 != 0x0) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                                    temp_0 = 0x1;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x0;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax == 0x2) {
                                                                                            eax = ((var_4 & 0xff) << 0x8) + (var_3 & 0xff);
                                                                                            ecx = eax & 0xffff;
                                                                                            eax = var_10;
                                                                                            ebx = ebx + 0x1;
                                                                                            bool_66 = true;
                                                                                            if (ecx == esi) {
                                                                                                    if (esi != 0x0) {
                                                                                                            edx = arg_0;
                                                                                                            continue;
                                                                                                    }
                                                                                                    if (var_8 != 0x0) {
                                                                                                            eax = var_C;
                                                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                                            temp_0 = 0x3;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_0 = 0x3;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                                    if (var_8 != 0x0) {
                                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                                            temp_0 = 0x1;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_0 = 0x0;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    edx = ecx & 0xffff;
                                                                    ecx = edx + eax;
                                                                    if ((ecx[0x1d] & 0x10) != 0x0) {
                                                                            ecx = ecx[0x11d] & 0xff;
                                                                            ecx = ecx & 0xffff;
                                                                    }
                                                                    else {
                                                                            ecx = edx & 0xffff;
                                                                    }
                                                                    bool_53 = true;
                                                                    if (ecx == esi) {
                                                                            if (esi != 0x0) {
                                                                                    edx = arg_0;
                                                                                    continue;
                                                                            }
                                                                            if (var_8 != 0x0) {
                                                                                    eax = var_C;
                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                    temp_0 = 0x3;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x3;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    temp_0 = 0x1;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x0;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (eax == 0x2) {
                                                                    eax = ((var_4 & 0xff) << 0x8) + (var_3 & 0xff);
                                                                    arg_0 = arg_0 + 0x1;
                                                                    esi = eax & 0xffff;
                                                                    eax = var_10;
                                                                    ecx = *(int8_t *)ebx & 0xff;
                                                                    ecx = ecx & 0xffff;
                                                                    ebx = ebx + 0x1;
                                                                    if ((*(int8_t *)((ecx & 0xff) + eax + 0x1d) & 0x4) != 0x0) {
                                                                            if (*(int8_t *)ebx == 0x0) {
                                                                                    bool_99 = true;
                                                                                    if (0x0 == esi) {
                                                                                            if (esi != 0x0) {
                                                                                                    edx = arg_0;
                                                                                                    continue;
                                                                                            }
                                                                                            if (var_8 != 0x0) {
                                                                                                    eax = var_C;
                                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                                    temp_0 = 0x3;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x3;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                            if (var_8 != 0x0) {
                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                                    temp_0 = 0x1;
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x0;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_482d50(&var_14, eax[0x3], 0x200, ebx - 0x1, 0x2, &var_4, 0x2, eax[0x1], 0x1);
                                                                                    esp = (esp - 0x24) + 0x24;
                                                                                    if (eax == 0x1) {
                                                                                            eax = var_4 & 0xff;
                                                                                            ecx = eax & 0xffff;
                                                                                            eax = var_10;
                                                                                            ebx = ebx + 0x1;
                                                                                            bool_32 = true;
                                                                                            if (ecx == esi) {
                                                                                                    if (esi != 0x0) {
                                                                                                            edx = arg_0;
                                                                                                            continue;
                                                                                                    }
                                                                                                    if (var_8 != 0x0) {
                                                                                                            eax = var_C;
                                                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                                            temp_0 = 0x3;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_0 = 0x3;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                                    if (var_8 != 0x0) {
                                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                                            temp_0 = 0x1;
                                                                                                    }
                                                                                                    else {
                                                                                                            temp_0 = 0x0;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax == 0x2) {
                                                                                                    eax = ((var_4 & 0xff) << 0x8) + (var_3 & 0xff);
                                                                                                    ecx = eax & 0xffff;
                                                                                                    eax = var_10;
                                                                                                    ebx = ebx + 0x1;
                                                                                                    bool_62 = true;
                                                                                                    if (ecx == esi) {
                                                                                                            if (esi != 0x0) {
                                                                                                                    edx = arg_0;
                                                                                                                    continue;
                                                                                                            }
                                                                                                            if (var_8 != 0x0) {
                                                                                                                    eax = var_C;
                                                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                                                    temp_0 = 0x3;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_0 = 0x3;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                                            if (var_8 != 0x0) {
                                                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                                                    temp_0 = 0x1;
                                                                                                            }
                                                                                                            else {
                                                                                                                    temp_0 = 0x0;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    temp_0 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            edx = ecx & 0xffff;
                                                                            ecx = edx + eax;
                                                                            if ((ecx[0x1d] & 0x10) != 0x0) {
                                                                                    ecx = ecx[0x11d] & 0xff;
                                                                                    ecx = ecx & 0xffff;
                                                                            }
                                                                            else {
                                                                                    ecx = edx & 0xffff;
                                                                            }
                                                                            bool_24 = true;
                                                                            if (ecx == esi) {
                                                                                    if (esi != 0x0) {
                                                                                            edx = arg_0;
                                                                                            continue;
                                                                                    }
                                                                                    if (var_8 != 0x0) {
                                                                                            eax = var_C;
                                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                    if (var_8 != 0x0) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x0;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            edx = ecx & 0xffff;
                                            ecx = edx + eax;
                                            if ((ecx[0x1d] & 0x10) != 0x0) {
                                                    esi = ecx[0x11d] & 0xff & 0xffff;
                                            }
                                            else {
                                                    esi = edx & 0xffff;
                                            }
                                            ecx = *(int8_t *)ebx & 0xff;
                                            ecx = ecx & 0xffff;
                                            ebx = ebx + 0x1;
                                            if ((*(int8_t *)((ecx & 0xff) + eax + 0x1d) & 0x4) != 0x0) {
                                                    if (*(int8_t *)ebx == 0x0) {
                                                            bool_44 = true;
                                                            if (0x0 == esi) {
                                                                    if (esi != 0x0) {
                                                                            edx = arg_0;
                                                                            continue;
                                                                    }
                                                                    if (var_8 != 0x0) {
                                                                            eax = var_C;
                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                            temp_0 = 0x3;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x3;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                    if (var_8 != 0x0) {
                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                            temp_0 = 0x1;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x0;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_482d50(&var_14, eax[0x3], 0x200, ebx - 0x1, 0x2, &var_4, 0x2, eax[0x1], 0x1);
                                                            esp = (esp - 0x24) + 0x24;
                                                            if (eax == 0x1) {
                                                                    eax = var_4 & 0xff;
                                                                    ecx = eax & 0xffff;
                                                                    eax = var_10;
                                                                    ebx = ebx + 0x1;
                                                                    bool_20 = true;
                                                                    if (ecx == esi) {
                                                                            if (esi != 0x0) {
                                                                                    edx = arg_0;
                                                                                    continue;
                                                                            }
                                                                            if (var_8 != 0x0) {
                                                                                    eax = var_C;
                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                    temp_0 = 0x3;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x3;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                            if (var_8 != 0x0) {
                                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                    temp_0 = 0x1;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x0;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax == 0x2) {
                                                                            eax = ((var_4 & 0xff) << 0x8) + (var_3 & 0xff);
                                                                            ecx = eax & 0xffff;
                                                                            eax = var_10;
                                                                            ebx = ebx + 0x1;
                                                                            bool_39 = true;
                                                                            if (ecx == esi) {
                                                                                    if (esi != 0x0) {
                                                                                            edx = arg_0;
                                                                                            continue;
                                                                                    }
                                                                                    if (var_8 != 0x0) {
                                                                                            eax = var_C;
                                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x3;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                                                    if (var_8 != 0x0) {
                                                                                            var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                                            temp_0 = 0x1;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x0;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    edx = ecx & 0xffff;
                                                    ecx = edx + eax;
                                                    if ((ecx[0x1d] & 0x10) != 0x0) {
                                                            ecx = ecx[0x11d] & 0xff;
                                                            ecx = ecx & 0xffff;
                                                    }
                                                    else {
                                                            ecx = edx & 0xffff;
                                                    }
                                                    bool_111 = true;
                                                    if (ecx == esi) {
                                                            if (esi != 0x0) {
                                                                    edx = arg_0;
                                                                    continue;
                                                            }
                                                            if (var_8 != 0x0) {
                                                                    eax = var_C;
                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                    temp_0 = 0x3;
                                                            }
                                                            else {
                                                                    temp_0 = 0x3;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            eax = (eax - eax + CARRY(EFLAGS(cf)) & 0x2) - 0x1;
                                                            if (var_8 != 0x0) {
                                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                                                    temp_0 = 0x1;
                                                            }
                                                            else {
                                                                    temp_0 = 0x0;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                            }
                            if (temp_0 != 0x0 && temp_0 != 0x1) {
                                    if (temp_0 != 0x2) {
                                            eax = 0x0;
                                    }
                                    else {
                                            *sub_47d812() = 0x16;
                                            if (var_8 != 0x0) {
                                                    var_C[0x1c] = var_C[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x7fffffff;
                                    }
                            }
                            esp = esp + 0x4;
                    }
            }
            esp = esp + 0x4;
    }
    return eax;
}
