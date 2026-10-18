// sub_48f102 @ 0x48f102
// hopper name: sub_48f102
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f102() {
    esp = esp - 0x4;
    decomp_var_14 = ebx;
    if (arg_8 != 0x0) {
            decomp_var_18 = edi;
            esp = esp - 0x8;
            sub_47aea2(arg_c);
            edi = var_C;
            if (edi[0x2] == 0x0) {
                    sub_48c337(arg_0, arg_4, arg_8);
                    esp = (esp - 0xc) + 0xc;
                    if (var_4 != 0x0) {
                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                    }
            }
            else {
                    ebx = 0x0;
                    if (arg_0 == 0x0) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            if (var_4 != ebx) {
                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_1c = esi;
                            esi = arg_4;
                            if (esi == ebx) {
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    if (var_4 != ebx) {
                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                    }
                            }
                            else {
                                    while (true) {
                                            ecx = *(int8_t *)arg_0 & 0xff;
                                            arg_8 = arg_8 - 0x1;
                                            ecx = ecx & 0xffff;
                                            eax = arg_0 + 0x1;
                                            arg_0 = eax;
                                            if ((*(int8_t *)((ecx & 0xff) + edi + 0x1d) & 0x4) != 0x0) {
                                                    if (arg_8 == 0x0) {
                                                            eax = *(int8_t *)esi & 0xff;
                                                            if ((*(int8_t *)(eax + edi + 0x1d) & 0x4) == 0x0) {
                                                                    eax = eax & 0xffff;
                                                                    bool_23 = true;
                                                                    if (eax == 0x0) {
                                                                            ebx = 0x0;
                                                                            if (0x0 != 0x0) {
                                                                                    if (arg_8 != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x2;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (var_4 != 0x0) {
                                                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                                                    temp_0 = 0x3;
                                                                            }
                                                                            else {
                                                                                    temp_0 = 0x0;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ebx = 0x0;
                                                            eax = *(int8_t *)eax;
                                                            if (eax == 0x0) {
                                                                    ecx = 0x0;
                                                            }
                                                            else {
                                                                    arg_0 = arg_0 + 0x1;
                                                                    ecx = eax & 0xffff;
                                                            }
                                                            eax = *(int8_t *)esi & 0xff;
                                                            eax = eax & 0xffff;
                                                            esi = esi + 0x1;
                                                            if ((*(int8_t *)((eax & 0xff) + edi + 0x1d) & 0x4) != 0x0) {
                                                                    if (arg_8 == ebx) {
                                                                            eax = 0x0;
                                                                    }
                                                                    else {
                                                                            edx = *(int8_t *)esi;
                                                                            arg_8 = arg_8 - 0x1;
                                                                            if (edx != 0x0) {
                                                                                    esi = esi + 0x1;
                                                                                    eax = edx & 0xffff;
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                            }
                                                            bool_27 = true;
                                                            if (eax == ecx) {
                                                                    if (ecx != 0x0) {
                                                                            if (arg_8 != 0x0) {
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (var_4 != 0x0) {
                                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                                            temp_0 = 0x3;
                                                                    }
                                                                    else {
                                                                            temp_0 = 0x0;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = *(int8_t *)esi & 0xff;
                                                    eax = eax & 0xffff;
                                                    esi = esi + 0x1;
                                                    if ((*(int8_t *)((eax & 0xff) + edi + 0x1d) & 0x4) != 0x0) {
                                                            if (arg_8 == 0x0) {
                                                                    eax = 0x0;
                                                            }
                                                            else {
                                                                    edx = *(int8_t *)esi;
                                                                    arg_8 = arg_8 - 0x1;
                                                                    if (edx != 0x0) {
                                                                            esi = esi + 0x1;
                                                                            eax = edx & 0xffff;
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                    }
                                                    bool_16 = true;
                                                    if (eax == ecx) {
                                                            if (ecx != 0x0) {
                                                                    if (arg_8 != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x2;
                                                                    break;
                                                            }
                                                            else {
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (var_4 != 0x0) {
                                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                                    temp_0 = 0x3;
                                                            }
                                                            else {
                                                                    temp_0 = 0x0;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    if (temp_0 != 0x0) {
                                            if (temp_0 != 0x1) {
                                                    if (temp_0 == 0x2 && var_4 != 0x0) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                            }
                                            else {
                                                    if (var_4 != 0x0) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                            }
                                    }
                            }
                            esp = esp + 0x4;
                    }
            }
            esp = esp + 0x4;
    }
    return;
}
