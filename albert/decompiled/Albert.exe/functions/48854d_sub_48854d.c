// sub_48854d @ 0x48854d
// hopper name: sub_48854d
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48854d() {
    eax = *dword_bc7210;
    eax = eax * 0x14 + *dword_bc7214;
    var_10 = arg_0 + 0x17 & 0xfffffff0;
    decomp_var_18 = ebx;
    ecx = (SAR((arg_0 + 0x17 & 0xfffffff0), 0x4)) - 0x1;
    decomp_var_1c = esi;
    esp = esp - 0xc;
    decomp_var_20 = edi;
    if (ecx < 0x20) {
            esi = (esi | 0xffffffff) >> ecx;
            var_8 = var_8 | 0xffffffff;
    }
    else {
            esi = 0x0;
            var_8 = (edx | 0xffffffff) >> ecx - 0x20;
    }
    ebx = *dword_bc721c;
    while (true) {
            arg_0 = ebx;
            if (ebx >= eax) {
                    break;
            }
            if ((ebx[0x1] & var_8 | *ebx & esi) != 0x0) {
                    break;
            }
            ebx = ebx + 0x14;
    }
    if (ebx == eax) {
            ebx = *dword_bc7214;
            while (true) {
                    arg_0 = ebx;
                    if (ebx >= *dword_bc721c) {
                            break;
                    }
                    if ((ebx[0x1] & var_8 | *ebx & esi) != 0x0) {
                            break;
                    }
                    ebx = ebx + 0x14;
            }
            if (ebx == *dword_bc721c) {
                    while (ebx < eax) {
                            if (ebx[0x2] != 0x0) {
                                    break;
                            }
                            ebx = ebx + 0x14;
                            arg_0 = ebx;
                    }
                    if (ebx == eax) {
                            ebx = *dword_bc7214;
                            while (true) {
                                    arg_0 = ebx;
                                    if (ebx >= *dword_bc721c) {
                                            break;
                                    }
                                    if (ebx[0x2] != 0x0) {
                                            break;
                                    }
                                    ebx = ebx + 0x14;
                            }
                            if (ebx == *dword_bc721c) {
                                    ebx = sub_4880b8();
                                    arg_0 = ebx;
                                    if (ebx == 0x0) {
                                            eax = 0x0;
                                    }
                                    else {
                                            esp = (esp - 0x4) + 0x4;
                                            *ebx[0x4] = sub_488168(ebx);
                                            if (*ebx[0x4] != 0xffffffff) {
                                                    *dword_bc721c = ebx;
                                                    eax = ebx[0x4];
                                                    edx = *eax;
                                                    var_4 = edx;
                                                    if (edx != 0xffffffff) {
                                                            if ((*(eax + edx * 0x4 + 0xc4) & var_8 | *(eax + edx * 0x4 + 0x44) & esi) == 0x0) {
                                                                    var_4 = var_4 & 0x0;
                                                                    edx = eax[0x31];
                                                                    ecx = eax + 0x44;
                                                                    while ((edx & var_8 | *ecx & esi) == 0x0) {
                                                                            var_4 = var_4 + 0x1;
                                                                            edx = ecx[0x21];
                                                                            ecx = ecx + 0x4;
                                                                    }
                                                                    edx = var_4;
                                                            }
                                                    }
                                                    else {
                                                            var_4 = var_4 & 0x0;
                                                            edx = eax[0x31];
                                                            ecx = eax + 0x44;
                                                            while ((edx & var_8 | *ecx & esi) == 0x0) {
                                                                    var_4 = var_4 + 0x1;
                                                                    edx = ecx[0x21];
                                                                    ecx = ecx + 0x4;
                                                            }
                                                            edx = var_4;
                                                    }
                                                    var_C = edx * 0x204 + eax + 0x144;
                                                    ecx = *(eax + edx * 0x4 + 0x44);
                                                    edi = 0x0;
                                                    ecx = ecx & esi;
                                                    if (ecx == 0x0) {
                                                            ecx = *(eax + edx * 0x4 + 0xc4);
                                                            ecx = ecx & var_8;
                                                            edi = 0x20;
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    while (ecx >= 0x0) {
                                                            ecx = ecx + ecx;
                                                            edi = edi + 0x1;
                                                    }
                                                    edx = *(var_C + edi * 0x8 + 0x4);
                                                    ecx = *edx;
                                                    ecx = ecx - var_10;
                                                    esi = (SAR(ecx, 0x4)) - 0x1;
                                                    var_8 = ecx;
                                                    if (esi > 0x3f) {
                                                            esi = 0x3f;
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    if (esi != edi) {
                                                            if (edx[0x1] == edx[0x2]) {
                                                                    if (edi < 0x20) {
                                                                            var_14 = !(0x80000000 >> edi);
                                                                            *(eax + var_4 * 0x4 + 0x44) = !(0x80000000 >> edi) & *(eax + var_4 * 0x4 + 0x44);
                                                                            *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                                                            if (*(int8_t *)edi == 0x0) {
                                                                                    ebx = arg_0;
                                                                                    *ebx = *ebx & var_14;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_0;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) & !(0x80000000 >> edi - 0x20);
                                                                            *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                                                            var_14 = !(0x80000000 >> edi - 0x20);
                                                                            if (*(int8_t *)edi == 0x0) {
                                                                                    ebx = arg_0;
                                                                                    ebx[0x1] = ebx[0x1] & var_14;
                                                                            }
                                                                            else {
                                                                                    ebx = arg_0;
                                                                            }
                                                                    }
                                                            }
                                                            *(edx[0x2] + 0x4) = edx[0x1];
                                                            *(edx[0x1] + 0x8) = edx[0x2];
                                                            if (var_8 != 0x0) {
                                                                    edi = *(var_C + esi * 0x8 + 0x4);
                                                                    edx[0x2] = var_C + esi * 0x8;
                                                                    edx[0x1] = edi;
                                                                    *(var_C + esi * 0x8 + 0x4) = edx;
                                                                    *(edx[0x1] + 0x8) = edx;
                                                                    if (edx[0x1] == edx[0x2]) {
                                                                            ecx = *(int8_t *)(esi + eax + 0x4);
                                                                            arg_3 = ecx;
                                                                            *(int8_t *)(esi + eax + 0x4) = ecx + 0x1;
                                                                            if (esi < 0x20) {
                                                                                    if (arg_3 == 0x0) {
                                                                                            *ebx = *ebx | 0x80000000 >> esi;
                                                                                    }
                                                                                    *(eax + var_4 * 0x4 + 0x44) = *(eax + var_4 * 0x4 + 0x44) | 0x80000000 >> esi;
                                                                            }
                                                                            else {
                                                                                    if (arg_3 == 0x0) {
                                                                                            ebx[0x1] = ebx[0x1] | 0x80000000 >> esi - 0x20;
                                                                                    }
                                                                                    *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) | 0x80000000 >> esi - 0x20;
                                                                            }
                                                                    }
                                                                    ecx = var_8;
                                                                    if (ecx != 0x0) {
                                                                            *edx = ecx;
                                                                            *(ecx + (edx - 0x4)) = ecx;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = var_8;
                                                            }
                                                    }
                                                    else {
                                                            if (ecx != 0x0) {
                                                                    *edx = ecx;
                                                                    *(ecx + (edx - 0x4)) = ecx;
                                                            }
                                                    }
                                                    edx = edx + ecx;
                                                    *edx = var_10 + 0x1;
                                                    *(edx + (var_10 - 0x4)) = var_10 + 0x1;
                                                    ecx = *var_C;
                                                    *var_C = ecx + 0x1;
                                                    if (ecx == 0x0 && ebx == *dword_bc69f0) {
                                                            if (var_4 == *dword_bc7224) {
                                                                    *dword_bc69f0 = *dword_bc69f0 & 0x0;
                                                            }
                                                    }
                                                    *eax = var_4;
                                                    eax = edx + 0x4;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                            }
                            else {
                                    esp = (esp - 0x4) + 0x4;
                                    *ebx[0x4] = sub_488168(ebx);
                                    if (*ebx[0x4] != 0xffffffff) {
                                            *dword_bc721c = ebx;
                                            eax = ebx[0x4];
                                            edx = *eax;
                                            var_4 = edx;
                                            if (edx != 0xffffffff) {
                                                    if ((*(eax + edx * 0x4 + 0xc4) & var_8 | *(eax + edx * 0x4 + 0x44) & esi) == 0x0) {
                                                            var_4 = var_4 & 0x0;
                                                            edx = eax[0x31];
                                                            ecx = eax + 0x44;
                                                            while ((edx & var_8 | *ecx & esi) == 0x0) {
                                                                    var_4 = var_4 + 0x1;
                                                                    edx = ecx[0x21];
                                                                    ecx = ecx + 0x4;
                                                            }
                                                            edx = var_4;
                                                    }
                                            }
                                            else {
                                                    var_4 = var_4 & 0x0;
                                                    edx = eax[0x31];
                                                    ecx = eax + 0x44;
                                                    while ((edx & var_8 | *ecx & esi) == 0x0) {
                                                            var_4 = var_4 + 0x1;
                                                            edx = ecx[0x21];
                                                            ecx = ecx + 0x4;
                                                    }
                                                    edx = var_4;
                                            }
                                            var_C = edx * 0x204 + eax + 0x144;
                                            ecx = *(eax + edx * 0x4 + 0x44);
                                            edi = 0x0;
                                            ecx = ecx & esi;
                                            if (ecx == 0x0) {
                                                    ecx = *(eax + edx * 0x4 + 0xc4);
                                                    ecx = ecx & var_8;
                                                    edi = 0x20;
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            while (ecx >= 0x0) {
                                                    ecx = ecx + ecx;
                                                    edi = edi + 0x1;
                                            }
                                            edx = *(var_C + edi * 0x8 + 0x4);
                                            ecx = *edx;
                                            ecx = ecx - var_10;
                                            esi = (SAR(ecx, 0x4)) - 0x1;
                                            var_8 = ecx;
                                            if (esi > 0x3f) {
                                                    esi = 0x3f;
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            if (esi != edi) {
                                                    if (edx[0x1] == edx[0x2]) {
                                                            if (edi < 0x20) {
                                                                    var_14 = !(0x80000000 >> edi);
                                                                    *(eax + var_4 * 0x4 + 0x44) = !(0x80000000 >> edi) & *(eax + var_4 * 0x4 + 0x44);
                                                                    *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                                                    if (*(int8_t *)edi == 0x0) {
                                                                            ebx = arg_0;
                                                                            *ebx = *ebx & var_14;
                                                                    }
                                                                    else {
                                                                            ebx = arg_0;
                                                                    }
                                                            }
                                                            else {
                                                                    *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) & !(0x80000000 >> edi - 0x20);
                                                                    *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                                                    var_14 = !(0x80000000 >> edi - 0x20);
                                                                    if (*(int8_t *)edi == 0x0) {
                                                                            ebx = arg_0;
                                                                            ebx[0x1] = ebx[0x1] & var_14;
                                                                    }
                                                                    else {
                                                                            ebx = arg_0;
                                                                    }
                                                            }
                                                    }
                                                    *(edx[0x2] + 0x4) = edx[0x1];
                                                    *(edx[0x1] + 0x8) = edx[0x2];
                                                    if (var_8 != 0x0) {
                                                            edi = *(var_C + esi * 0x8 + 0x4);
                                                            edx[0x2] = var_C + esi * 0x8;
                                                            edx[0x1] = edi;
                                                            *(var_C + esi * 0x8 + 0x4) = edx;
                                                            *(edx[0x1] + 0x8) = edx;
                                                            if (edx[0x1] == edx[0x2]) {
                                                                    ecx = *(int8_t *)(esi + eax + 0x4);
                                                                    arg_3 = ecx;
                                                                    *(int8_t *)(esi + eax + 0x4) = ecx + 0x1;
                                                                    if (esi < 0x20) {
                                                                            if (arg_3 == 0x0) {
                                                                                    *ebx = *ebx | 0x80000000 >> esi;
                                                                            }
                                                                            *(eax + var_4 * 0x4 + 0x44) = *(eax + var_4 * 0x4 + 0x44) | 0x80000000 >> esi;
                                                                    }
                                                                    else {
                                                                            if (arg_3 == 0x0) {
                                                                                    ebx[0x1] = ebx[0x1] | 0x80000000 >> esi - 0x20;
                                                                            }
                                                                            *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) | 0x80000000 >> esi - 0x20;
                                                                    }
                                                            }
                                                            ecx = var_8;
                                                            if (ecx != 0x0) {
                                                                    *edx = ecx;
                                                                    *(ecx + (edx - 0x4)) = ecx;
                                                            }
                                                    }
                                                    else {
                                                            ecx = var_8;
                                                    }
                                            }
                                            else {
                                                    if (ecx != 0x0) {
                                                            *edx = ecx;
                                                            *(ecx + (edx - 0x4)) = ecx;
                                                    }
                                            }
                                            edx = edx + ecx;
                                            *edx = var_10 + 0x1;
                                            *(edx + (var_10 - 0x4)) = var_10 + 0x1;
                                            ecx = *var_C;
                                            *var_C = ecx + 0x1;
                                            if (ecx == 0x0 && ebx == *dword_bc69f0) {
                                                    if (var_4 == *dword_bc7224) {
                                                            *dword_bc69f0 = *dword_bc69f0 & 0x0;
                                                    }
                                            }
                                            *eax = var_4;
                                            eax = edx + 0x4;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
                    else {
                            esp = (esp - 0x4) + 0x4;
                            *ebx[0x4] = sub_488168(ebx);
                            if (*ebx[0x4] != 0xffffffff) {
                                    *dword_bc721c = ebx;
                                    eax = ebx[0x4];
                                    edx = *eax;
                                    var_4 = edx;
                                    if (edx != 0xffffffff) {
                                            if ((*(eax + edx * 0x4 + 0xc4) & var_8 | *(eax + edx * 0x4 + 0x44) & esi) == 0x0) {
                                                    var_4 = var_4 & 0x0;
                                                    edx = eax[0x31];
                                                    ecx = eax + 0x44;
                                                    while ((edx & var_8 | *ecx & esi) == 0x0) {
                                                            var_4 = var_4 + 0x1;
                                                            edx = ecx[0x21];
                                                            ecx = ecx + 0x4;
                                                    }
                                                    edx = var_4;
                                            }
                                    }
                                    else {
                                            var_4 = var_4 & 0x0;
                                            edx = eax[0x31];
                                            ecx = eax + 0x44;
                                            while ((edx & var_8 | *ecx & esi) == 0x0) {
                                                    var_4 = var_4 + 0x1;
                                                    edx = ecx[0x21];
                                                    ecx = ecx + 0x4;
                                            }
                                            edx = var_4;
                                    }
                                    var_C = edx * 0x204 + eax + 0x144;
                                    ecx = *(eax + edx * 0x4 + 0x44);
                                    edi = 0x0;
                                    ecx = ecx & esi;
                                    if (ecx == 0x0) {
                                            ecx = *(eax + edx * 0x4 + 0xc4);
                                            ecx = ecx & var_8;
                                            edi = 0x20;
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    while (ecx >= 0x0) {
                                            ecx = ecx + ecx;
                                            edi = edi + 0x1;
                                    }
                                    edx = *(var_C + edi * 0x8 + 0x4);
                                    ecx = *edx;
                                    ecx = ecx - var_10;
                                    esi = (SAR(ecx, 0x4)) - 0x1;
                                    var_8 = ecx;
                                    if (esi > 0x3f) {
                                            esi = 0x3f;
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    if (esi != edi) {
                                            if (edx[0x1] == edx[0x2]) {
                                                    if (edi < 0x20) {
                                                            var_14 = !(0x80000000 >> edi);
                                                            *(eax + var_4 * 0x4 + 0x44) = !(0x80000000 >> edi) & *(eax + var_4 * 0x4 + 0x44);
                                                            *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                                            if (*(int8_t *)edi == 0x0) {
                                                                    ebx = arg_0;
                                                                    *ebx = *ebx & var_14;
                                                            }
                                                            else {
                                                                    ebx = arg_0;
                                                            }
                                                    }
                                                    else {
                                                            *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) & !(0x80000000 >> edi - 0x20);
                                                            *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                                            var_14 = !(0x80000000 >> edi - 0x20);
                                                            if (*(int8_t *)edi == 0x0) {
                                                                    ebx = arg_0;
                                                                    ebx[0x1] = ebx[0x1] & var_14;
                                                            }
                                                            else {
                                                                    ebx = arg_0;
                                                            }
                                                    }
                                            }
                                            *(edx[0x2] + 0x4) = edx[0x1];
                                            *(edx[0x1] + 0x8) = edx[0x2];
                                            if (var_8 != 0x0) {
                                                    edi = *(var_C + esi * 0x8 + 0x4);
                                                    edx[0x2] = var_C + esi * 0x8;
                                                    edx[0x1] = edi;
                                                    *(var_C + esi * 0x8 + 0x4) = edx;
                                                    *(edx[0x1] + 0x8) = edx;
                                                    if (edx[0x1] == edx[0x2]) {
                                                            ecx = *(int8_t *)(esi + eax + 0x4);
                                                            arg_3 = ecx;
                                                            *(int8_t *)(esi + eax + 0x4) = ecx + 0x1;
                                                            if (esi < 0x20) {
                                                                    if (arg_3 == 0x0) {
                                                                            *ebx = *ebx | 0x80000000 >> esi;
                                                                    }
                                                                    *(eax + var_4 * 0x4 + 0x44) = *(eax + var_4 * 0x4 + 0x44) | 0x80000000 >> esi;
                                                            }
                                                            else {
                                                                    if (arg_3 == 0x0) {
                                                                            ebx[0x1] = ebx[0x1] | 0x80000000 >> esi - 0x20;
                                                                    }
                                                                    *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) | 0x80000000 >> esi - 0x20;
                                                            }
                                                    }
                                                    ecx = var_8;
                                                    if (ecx != 0x0) {
                                                            *edx = ecx;
                                                            *(ecx + (edx - 0x4)) = ecx;
                                                    }
                                            }
                                            else {
                                                    ecx = var_8;
                                            }
                                    }
                                    else {
                                            if (ecx != 0x0) {
                                                    *edx = ecx;
                                                    *(ecx + (edx - 0x4)) = ecx;
                                            }
                                    }
                                    edx = edx + ecx;
                                    *edx = var_10 + 0x1;
                                    *(edx + (var_10 - 0x4)) = var_10 + 0x1;
                                    ecx = *var_C;
                                    *var_C = ecx + 0x1;
                                    if (ecx == 0x0 && ebx == *dword_bc69f0) {
                                            if (var_4 == *dword_bc7224) {
                                                    *dword_bc69f0 = *dword_bc69f0 & 0x0;
                                            }
                                    }
                                    *eax = var_4;
                                    eax = edx + 0x4;
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
            else {
                    *dword_bc721c = ebx;
                    eax = ebx[0x4];
                    edx = *eax;
                    var_4 = edx;
                    if (edx != 0xffffffff) {
                            if ((*(eax + edx * 0x4 + 0xc4) & var_8 | *(eax + edx * 0x4 + 0x44) & esi) == 0x0) {
                                    var_4 = var_4 & 0x0;
                                    edx = eax[0x31];
                                    ecx = eax + 0x44;
                                    while ((edx & var_8 | *ecx & esi) == 0x0) {
                                            var_4 = var_4 + 0x1;
                                            edx = ecx[0x21];
                                            ecx = ecx + 0x4;
                                    }
                                    edx = var_4;
                            }
                    }
                    else {
                            var_4 = var_4 & 0x0;
                            edx = eax[0x31];
                            ecx = eax + 0x44;
                            while ((edx & var_8 | *ecx & esi) == 0x0) {
                                    var_4 = var_4 + 0x1;
                                    edx = ecx[0x21];
                                    ecx = ecx + 0x4;
                            }
                            edx = var_4;
                    }
                    var_C = edx * 0x204 + eax + 0x144;
                    ecx = *(eax + edx * 0x4 + 0x44);
                    edi = 0x0;
                    ecx = ecx & esi;
                    if (ecx == 0x0) {
                            ecx = *(eax + edx * 0x4 + 0xc4);
                            ecx = ecx & var_8;
                            edi = 0x20;
                            esp = (esp - 0x4) + 0x4;
                    }
                    while (ecx >= 0x0) {
                            ecx = ecx + ecx;
                            edi = edi + 0x1;
                    }
                    edx = *(var_C + edi * 0x8 + 0x4);
                    ecx = *edx;
                    ecx = ecx - var_10;
                    esi = (SAR(ecx, 0x4)) - 0x1;
                    var_8 = ecx;
                    if (esi > 0x3f) {
                            esi = 0x3f;
                            esp = (esp - 0x4) + 0x4;
                    }
                    if (esi != edi) {
                            if (edx[0x1] == edx[0x2]) {
                                    if (edi < 0x20) {
                                            var_14 = !(0x80000000 >> edi);
                                            *(eax + var_4 * 0x4 + 0x44) = !(0x80000000 >> edi) & *(eax + var_4 * 0x4 + 0x44);
                                            *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                            if (*(int8_t *)edi == 0x0) {
                                                    ebx = arg_0;
                                                    *ebx = *ebx & var_14;
                                            }
                                            else {
                                                    ebx = arg_0;
                                            }
                                    }
                                    else {
                                            *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) & !(0x80000000 >> edi - 0x20);
                                            *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                            var_14 = !(0x80000000 >> edi - 0x20);
                                            if (*(int8_t *)edi == 0x0) {
                                                    ebx = arg_0;
                                                    ebx[0x1] = ebx[0x1] & var_14;
                                            }
                                            else {
                                                    ebx = arg_0;
                                            }
                                    }
                            }
                            *(edx[0x2] + 0x4) = edx[0x1];
                            *(edx[0x1] + 0x8) = edx[0x2];
                            if (var_8 != 0x0) {
                                    edi = *(var_C + esi * 0x8 + 0x4);
                                    edx[0x2] = var_C + esi * 0x8;
                                    edx[0x1] = edi;
                                    *(var_C + esi * 0x8 + 0x4) = edx;
                                    *(edx[0x1] + 0x8) = edx;
                                    if (edx[0x1] == edx[0x2]) {
                                            ecx = *(int8_t *)(esi + eax + 0x4);
                                            arg_3 = ecx;
                                            *(int8_t *)(esi + eax + 0x4) = ecx + 0x1;
                                            if (esi < 0x20) {
                                                    if (arg_3 == 0x0) {
                                                            *ebx = *ebx | 0x80000000 >> esi;
                                                    }
                                                    *(eax + var_4 * 0x4 + 0x44) = *(eax + var_4 * 0x4 + 0x44) | 0x80000000 >> esi;
                                            }
                                            else {
                                                    if (arg_3 == 0x0) {
                                                            ebx[0x1] = ebx[0x1] | 0x80000000 >> esi - 0x20;
                                                    }
                                                    *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) | 0x80000000 >> esi - 0x20;
                                            }
                                    }
                                    ecx = var_8;
                                    if (ecx != 0x0) {
                                            *edx = ecx;
                                            *(ecx + (edx - 0x4)) = ecx;
                                    }
                            }
                            else {
                                    ecx = var_8;
                            }
                    }
                    else {
                            if (ecx != 0x0) {
                                    *edx = ecx;
                                    *(ecx + (edx - 0x4)) = ecx;
                            }
                    }
                    edx = edx + ecx;
                    *edx = var_10 + 0x1;
                    *(edx + (var_10 - 0x4)) = var_10 + 0x1;
                    ecx = *var_C;
                    *var_C = ecx + 0x1;
                    if (ecx == 0x0 && ebx == *dword_bc69f0) {
                            if (var_4 == *dword_bc7224) {
                                    *dword_bc69f0 = *dword_bc69f0 & 0x0;
                            }
                    }
                    *eax = var_4;
                    eax = edx + 0x4;
            }
    }
    else {
            *dword_bc721c = ebx;
            eax = ebx[0x4];
            edx = *eax;
            var_4 = edx;
            if (edx != 0xffffffff) {
                    if ((*(eax + edx * 0x4 + 0xc4) & var_8 | *(eax + edx * 0x4 + 0x44) & esi) == 0x0) {
                            var_4 = var_4 & 0x0;
                            edx = eax[0x31];
                            ecx = eax + 0x44;
                            while ((edx & var_8 | *ecx & esi) == 0x0) {
                                    var_4 = var_4 + 0x1;
                                    edx = ecx[0x21];
                                    ecx = ecx + 0x4;
                            }
                            edx = var_4;
                    }
            }
            else {
                    var_4 = var_4 & 0x0;
                    edx = eax[0x31];
                    ecx = eax + 0x44;
                    while ((edx & var_8 | *ecx & esi) == 0x0) {
                            var_4 = var_4 + 0x1;
                            edx = ecx[0x21];
                            ecx = ecx + 0x4;
                    }
                    edx = var_4;
            }
            var_C = edx * 0x204 + eax + 0x144;
            ecx = *(eax + edx * 0x4 + 0x44);
            edi = 0x0;
            ecx = ecx & esi;
            if (ecx == 0x0) {
                    ecx = *(eax + edx * 0x4 + 0xc4);
                    ecx = ecx & var_8;
                    edi = 0x20;
                    esp = (esp - 0x4) + 0x4;
            }
            while (ecx >= 0x0) {
                    ecx = ecx + ecx;
                    edi = edi + 0x1;
            }
            edx = *(var_C + edi * 0x8 + 0x4);
            ecx = *edx;
            ecx = ecx - var_10;
            esi = (SAR(ecx, 0x4)) - 0x1;
            var_8 = ecx;
            if (esi > 0x3f) {
                    esi = 0x3f;
                    esp = (esp - 0x4) + 0x4;
            }
            if (esi != edi) {
                    if (edx[0x1] == edx[0x2]) {
                            if (edi < 0x20) {
                                    var_14 = !(0x80000000 >> edi);
                                    *(eax + var_4 * 0x4 + 0x44) = !(0x80000000 >> edi) & *(eax + var_4 * 0x4 + 0x44);
                                    *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                    if (*(int8_t *)edi == 0x0) {
                                            ebx = arg_0;
                                            *ebx = *ebx & var_14;
                                    }
                                    else {
                                            ebx = arg_0;
                                    }
                            }
                            else {
                                    *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) & !(0x80000000 >> edi - 0x20);
                                    *(int8_t *)(eax + edi + 0x4) = *(int8_t *)(eax + edi + 0x4) - 0x1;
                                    var_14 = !(0x80000000 >> edi - 0x20);
                                    if (*(int8_t *)edi == 0x0) {
                                            ebx = arg_0;
                                            ebx[0x1] = ebx[0x1] & var_14;
                                    }
                                    else {
                                            ebx = arg_0;
                                    }
                            }
                    }
                    *(edx[0x2] + 0x4) = edx[0x1];
                    *(edx[0x1] + 0x8) = edx[0x2];
                    if (var_8 != 0x0) {
                            edi = *(var_C + esi * 0x8 + 0x4);
                            edx[0x2] = var_C + esi * 0x8;
                            edx[0x1] = edi;
                            *(var_C + esi * 0x8 + 0x4) = edx;
                            *(edx[0x1] + 0x8) = edx;
                            if (edx[0x1] == edx[0x2]) {
                                    ecx = *(int8_t *)(esi + eax + 0x4);
                                    arg_3 = ecx;
                                    *(int8_t *)(esi + eax + 0x4) = ecx + 0x1;
                                    if (esi < 0x20) {
                                            if (arg_3 == 0x0) {
                                                    *ebx = *ebx | 0x80000000 >> esi;
                                            }
                                            *(eax + var_4 * 0x4 + 0x44) = *(eax + var_4 * 0x4 + 0x44) | 0x80000000 >> esi;
                                    }
                                    else {
                                            if (arg_3 == 0x0) {
                                                    ebx[0x1] = ebx[0x1] | 0x80000000 >> esi - 0x20;
                                            }
                                            *(eax + var_4 * 0x4 + 0xc4) = *(eax + var_4 * 0x4 + 0xc4) | 0x80000000 >> esi - 0x20;
                                    }
                            }
                            ecx = var_8;
                            if (ecx != 0x0) {
                                    *edx = ecx;
                                    *(ecx + (edx - 0x4)) = ecx;
                            }
                    }
                    else {
                            ecx = var_8;
                    }
            }
            else {
                    if (ecx != 0x0) {
                            *edx = ecx;
                            *(ecx + (edx - 0x4)) = ecx;
                    }
            }
            edx = edx + ecx;
            *edx = var_10 + 0x1;
            *(edx + (var_10 - 0x4)) = var_10 + 0x1;
            ecx = *var_C;
            *var_C = ecx + 0x1;
            if (ecx == 0x0 && ebx == *dword_bc69f0) {
                    if (var_4 == *dword_bc7224) {
                            *dword_bc69f0 = *dword_bc69f0 & 0x0;
                    }
            }
            *eax = var_4;
            eax = edx + 0x4;
    }
    return eax;
}
