// sub_40c620 @ 0x40c620
// hopper name: sub_40c620
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40c620() {
    decomp_var_c = *0x0;
    decomp_var_3c = ebx;
    decomp_var_44 = esi;
    decomp_var_48 = edi;
    esp = esp - 0x4c;
    decomp_var_4c = *dword_4c8db8 ^ &decomp_var_48;
    *0x0 = &decomp_var_c;
    edi = ecx;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            decomp_var_34 = (*(*eax + 0xc))() + 0x10;
            eax = sub_47020b();
            if (eax == 0x0) {
                    eax = sub_40b5a0(0x80004005);
            }
            else {
                    edx = *eax;
                    (edx[0x3])() + 0x10;
                    ebx = arg_0;
                    edi = edi + 0xcc;
                    *(int8_t *)ebx = 0x0;
                    ebx[0x1] = 0x0;
                    ebx[0x8] = 0x0;
                    ebx[0xc] = 0x0;
                    ebx[0x14] = 0x0;
                    eax = *edi;
                    if (*(eax - 0xc) < 0x0) {
                            eax = sub_40b5a0(0x80070057);
                    }
                    else {
                            bool_42 = *(int8_t *)eax != 0x22;
                            eax = *edi;
                            if (!bool_42) {
                                    if (*(eax - 0xc) > 0x1) {
                                            decomp_var_50 = 0x22;
                                            decomp_var_54 = eax + 0x1;
                                            eax = sub_47b246(decomp_var_54, 0x22);
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax != 0x0) {
                                                    eax = eax - *edi;
                                                    if (eax != 0xffffffff) {
                                                            esp = esp - 0x8;
                                                            decomp_var_54 = &arg_0;
                                                            eax = sub_40c490(decomp_var_54, eax + 0x1);
                                                            esp = esp - 0x4;
                                                            decomp_var_50 = eax;
                                                            sub_40c410(decomp_var_50);
                                                            eax = arg_0 - 0x10;
                                                            edx = eax + 0xc;
                                                            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
                                                            if (ecx <= 0x1) {
                                                                    edx = **eax;
                                                                    esp = esp - 0x4;
                                                                    decomp_var_50 = eax;
                                                                    (edx[0x1])(decomp_var_50);
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if (*(eax - 0xc) > 0x0) {
                                            decomp_var_50 = 0x20;
                                            decomp_var_54 = eax;
                                            eax = sub_47b246(decomp_var_54, 0x20);
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax != 0x0) {
                                                    eax = eax - *edi;
                                                    if (eax != 0xffffffff) {
                                                            esp = esp - 0x8;
                                                            decomp_var_54 = &arg_0;
                                                            eax = sub_40c490(decomp_var_54, eax);
                                                            esp = esp - 0x4;
                                                            decomp_var_50 = eax;
                                                            sub_40c410(decomp_var_50);
                                                            eax = arg_0 - 0x10;
                                                            edx = eax + 0xc;
                                                            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
                                                            if (ecx <= 0x1) {
                                                                    edx = **eax;
                                                                    esp = esp - 0x4;
                                                                    decomp_var_50 = eax;
                                                                    (edx[0x1])(decomp_var_50);
                                                            }
                                                    }
                                            }
                                    }
                            }
                            eax = *edi;
                            if (*(eax - 0xc) > 0x0) {
                                    decomp_var_50 = 0x2d;
                                    decomp_var_54 = eax;
                                    eax = sub_47b246(decomp_var_54, 0x2d);
                                    esp = (esp - 0x8) + 0x8;
                                    if (eax != 0x0) {
                                            esi = eax - *edi;
                                            if (esi != 0xffffffff) {
                                                    while (true) {
                                                            eax = esi + 0x1;
                                                            if (eax < 0x0) {
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            ecx = *edi;
                                                            if (eax > *(ecx - 0xc)) {
                                                                    temp_0 = 0x6;
                                                                    break;
                                                            }
                                                            ecx = *(int8_t *)(ecx + eax);
                                                            eax = *edi;
                                                            arg_0 = ecx;
                                                            ecx = *(eax - 0xc);
                                                            if (esi >= 0x0) {
                                                                    if (esi <= ecx) {
                                                                            eax = sub_47b179(eax + esi, 0x4af9d0);
                                                                            esp = (esp - 0x8) + 0x8;
                                                                            if (eax != 0x0) {
                                                                                    ebp = eax - *edi;
                                                                                    if (ebp == 0xffffffff) {
                                                                                            decomp_var_54 = &decomp_var_28;
                                                                                            esp = esp - 0xc;
                                                                                            decomp_var_50 = sub_40c490(decomp_var_54, esi + 0x2);
                                                                                            sub_40c410(decomp_var_50);
                                                                                            eax = decomp_var_28 - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            edx = edx - 0x1;
                                                                                            if (edx <= 0x0) {
                                                                                                    edx = **eax;
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (edx[0x1])(decomp_var_50);
                                                                                            }
                                                                                            ebp = *(*edi - 0xc);
                                                                                    }
                                                                                    else {
                                                                                            eax = sub_40c260(&decomp_var_20, ebp);
                                                                                            decomp_var_54 = &decomp_var_24;
                                                                                            esp = esp - 0x14;
                                                                                            decomp_var_50 = sub_40c490(decomp_var_54, esi + 0x2);
                                                                                            sub_40c410(decomp_var_50);
                                                                                            eax = decomp_var_24 - 0x10;
                                                                                            edx = eax + 0xc;
                                                                                            *edx = lock intrinsic_xadd(*edx, ecx | 0xffffffff);
                                                                                            if (ecx <= 0x1) {
                                                                                                    edx = **eax;
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (edx[0x1])(decomp_var_50);
                                                                                            }
                                                                                            eax = decomp_var_20 - 0x10;
                                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                            edx = edx - 0x1;
                                                                                            if (edx <= 0x0) {
                                                                                                    edx = **eax;
                                                                                                    esp = esp - 0x4;
                                                                                                    decomp_var_50 = eax;
                                                                                                    (edx[0x1])(decomp_var_50);
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    decomp_var_54 = &decomp_var_28;
                                                                                    esp = esp - 0xc;
                                                                                    decomp_var_50 = sub_40c490(decomp_var_54, esi + 0x2);
                                                                                    sub_40c410(decomp_var_50);
                                                                                    eax = decomp_var_28 - 0x10;
                                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                                    edx = edx - 0x1;
                                                                                    if (edx <= 0x0) {
                                                                                            edx = **eax;
                                                                                            esp = esp - 0x4;
                                                                                            decomp_var_50 = eax;
                                                                                            (edx[0x1])(decomp_var_50);
                                                                                    }
                                                                                    ebp = *(*edi - 0xc);
                                                                            }
                                                                    }
                                                                    else {
                                                                            decomp_var_54 = &decomp_var_28;
                                                                            esp = esp - 0xc;
                                                                            decomp_var_50 = sub_40c490(decomp_var_54, esi + 0x2);
                                                                            sub_40c410(decomp_var_50);
                                                                            eax = decomp_var_28 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            edx = edx - 0x1;
                                                                            if (edx <= 0x0) {
                                                                                    edx = **eax;
                                                                                    esp = esp - 0x4;
                                                                                    decomp_var_50 = eax;
                                                                                    (edx[0x1])(decomp_var_50);
                                                                            }
                                                                            ebp = *(*edi - 0xc);
                                                                    }
                                                            }
                                                            else {
                                                                    decomp_var_54 = &decomp_var_28;
                                                                    esp = esp - 0xc;
                                                                    decomp_var_50 = sub_40c490(decomp_var_54, esi + 0x2);
                                                                    sub_40c410(decomp_var_50);
                                                                    eax = decomp_var_28 - 0x10;
                                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                    edx = edx - 0x1;
                                                                    if (edx <= 0x0) {
                                                                            edx = **eax;
                                                                            esp = esp - 0x4;
                                                                            decomp_var_50 = eax;
                                                                            (edx[0x1])(decomp_var_50);
                                                                    }
                                                                    ebp = *(*edi - 0xc);
                                                            }
                                                            eax = sign_extend_32(arg_0) - 0x48;
                                                            if (eax <= 0x2b) {
                                                                    eax = (*((eax[0x40cb98] & 0xff) * 0x4 + 0x40cb78))();
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            else {
                                                                    edx = arg_0;
                                                                    decomp_var_50 = &decomp_var_34;
                                                                    esp = esp - 0x8;
                                                                    decomp_var_54 = edx;
                                                                    if (sub_4106d0() == 0x0) {
                                                                            eax = sub_41c1b0(&decomp_var_1c);
                                                                            esp = esp - 0x8;
                                                                            sub_40c410(eax);
                                                                            eax = decomp_var_1c - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    edx = **eax;
                                                                                    esp = esp - 0x4;
                                                                                    (edx[0x1])(eax);
                                                                            }
                                                                            esp = (esp - 0xc) + 0xc - 0xc;
                                                                            sub_4700ea(*sub_40c4c0(), 0x0, 0x0);
                                                                            eax = decomp_var_18 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            edx = edx - 0x1;
                                                                            if (edx <= 0x0) {
                                                                                    edx = **eax;
                                                                                    esp = esp - 0x4;
                                                                                    (edx[0x1])(eax);
                                                                            }
                                                                            decomp_var_3d = 0x0;
                                                                    }
                                                                    eax = *edi;
                                                                    ecx = *(eax - 0xc);
                                                                    if (ebp >= 0x0) {
                                                                            if (ebp < ecx) {
                                                                                    eax = sub_47b246(eax + ebp, 0x2d);
                                                                                    esp = (esp - 0x8) + 0x8;
                                                                                    if (eax != 0x0) {
                                                                                            eax = eax - *edi;
                                                                                            esi = eax;
                                                                                            if (esi != 0xffffffff) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_0 = 0x5;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_0 = 0x4;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x3;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    switch (temp_0) {
                                                        case 0:
                                                            if (*(int8_t *)ebx != 0x0 && ebx[0x1] != 0x0) {
                                                                    esp = esp - 0xc;
                                                                    sub_4700ea("You must not specify Server name and IP address", 0x0, 0x0);
                                                                    decomp_var_3d = 0x0;
                                                            }
                                                            eax = decomp_var_38 - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            edx = edx - 0x1;
                                                            if (edx <= 0x0) {
                                                                    edx = **eax;
                                                                    esp = esp - 0x4;
                                                                    (edx[0x1])(eax);
                                                            }
                                                            eax = decomp_var_3c - 0x10;
                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                            if (edx <= 0x1) {
                                                                    esp = esp - 0x4;
                                                                    (*(**eax + 0x4))(eax);
                                                            }
                                                            eax = decomp_var_3d;
                                                            *0x0 = decomp_var_14;
                                                            break;
                                                        case 1:
                                                            eax = sub_40b5a0(0x80070057);
                                                            break;
                                                        default:
                                                            if (temp_0 != 0x2) {
                                                                    switch (temp_0) {
                                                                        case 3:
                                                                            if (*(int8_t *)ebx != 0x0 && ebx[0x1] != 0x0) {
                                                                                    esp = esp - 0xc;
                                                                                    sub_4700ea("You must not specify Server name and IP address", 0x0, 0x0);
                                                                                    decomp_var_3d = 0x0;
                                                                            }
                                                                            eax = decomp_var_38 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            edx = edx - 0x1;
                                                                            if (edx <= 0x0) {
                                                                                    edx = **eax;
                                                                                    esp = esp - 0x4;
                                                                                    (edx[0x1])(eax);
                                                                            }
                                                                            eax = decomp_var_3c - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            eax = decomp_var_3d;
                                                                            *0x0 = decomp_var_14;
                                                                            break;
                                                                        case 4:
                                                                            if (*(int8_t *)ebx != 0x0 && ebx[0x1] != 0x0) {
                                                                                    esp = esp - 0xc;
                                                                                    sub_4700ea("You must not specify Server name and IP address", 0x0, 0x0);
                                                                                    decomp_var_3d = 0x0;
                                                                            }
                                                                            eax = decomp_var_38 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            edx = edx - 0x1;
                                                                            if (edx <= 0x0) {
                                                                                    edx = **eax;
                                                                                    esp = esp - 0x4;
                                                                                    (edx[0x1])(eax);
                                                                            }
                                                                            eax = decomp_var_3c - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            eax = decomp_var_3d;
                                                                            *0x0 = decomp_var_14;
                                                                            break;
                                                                        case 5:
                                                                            if (*(int8_t *)ebx != 0x0 && ebx[0x1] != 0x0) {
                                                                                    esp = esp - 0xc;
                                                                                    sub_4700ea("You must not specify Server name and IP address", 0x0, 0x0);
                                                                                    decomp_var_3d = 0x0;
                                                                            }
                                                                            eax = decomp_var_38 - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            edx = edx - 0x1;
                                                                            if (edx <= 0x0) {
                                                                                    edx = **eax;
                                                                                    esp = esp - 0x4;
                                                                                    (edx[0x1])(eax);
                                                                            }
                                                                            eax = decomp_var_3c - 0x10;
                                                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                                            if (edx <= 0x1) {
                                                                                    esp = esp - 0x4;
                                                                                    (*(**eax + 0x4))(eax);
                                                                            }
                                                                            eax = decomp_var_3d;
                                                                            *0x0 = decomp_var_14;
                                                                            break;
                                                                        default:
                                                                            eax = sub_40b5a0(0x80070057);
                                                                            break;
                                                                    }
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (*(int8_t *)ebx != 0x0 && ebx[0x1] != 0x0) {
                                                            esp = esp - 0xc;
                                                            sub_4700ea("You must not specify Server name and IP address", 0x0, 0x0);
                                                            decomp_var_3d = 0x0;
                                                    }
                                                    eax = decomp_var_38 - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    edx = edx - 0x1;
                                                    if (edx <= 0x0) {
                                                            edx = **eax;
                                                            esp = esp - 0x4;
                                                            (edx[0x1])(eax);
                                                    }
                                                    eax = decomp_var_3c - 0x10;
                                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                                    if (edx <= 0x1) {
                                                            esp = esp - 0x4;
                                                            (*(**eax + 0x4))(eax);
                                                    }
                                                    eax = decomp_var_3d;
                                                    *0x0 = decomp_var_14;
                                            }
                                    }
                                    else {
                                            if (*(int8_t *)ebx != 0x0 && ebx[0x1] != 0x0) {
                                                    esp = esp - 0xc;
                                                    sub_4700ea("You must not specify Server name and IP address", 0x0, 0x0);
                                                    decomp_var_3d = 0x0;
                                            }
                                            eax = decomp_var_38 - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            edx = edx - 0x1;
                                            if (edx <= 0x0) {
                                                    edx = **eax;
                                                    esp = esp - 0x4;
                                                    (edx[0x1])(eax);
                                            }
                                            eax = decomp_var_3c - 0x10;
                                            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                            if (edx <= 0x1) {
                                                    esp = esp - 0x4;
                                                    (*(**eax + 0x4))(eax);
                                            }
                                            eax = decomp_var_3d;
                                            *0x0 = decomp_var_14;
                                    }
                            }
                            else {
                                    if (*(int8_t *)ebx != 0x0 && ebx[0x1] != 0x0) {
                                            esp = esp - 0xc;
                                            sub_4700ea("You must not specify Server name and IP address", 0x0, 0x0);
                                            decomp_var_3d = 0x0;
                                    }
                                    eax = decomp_var_38 - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    edx = edx - 0x1;
                                    if (edx <= 0x0) {
                                            edx = **eax;
                                            esp = esp - 0x4;
                                            (edx[0x1])(eax);
                                    }
                                    eax = decomp_var_3c - 0x10;
                                    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
                                    if (edx <= 0x1) {
                                            esp = esp - 0x4;
                                            (*(**eax + 0x4))(eax);
                                    }
                                    eax = decomp_var_3d;
                                    *0x0 = decomp_var_14;
                            }
                    }
            }
    }
    return eax;
}
