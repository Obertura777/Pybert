// sub_48b7f9 @ 0x48b7f9
// hopper name: sub_48b7f9
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48b7f9() {
    var_4 = *dword_4c8db8 ^ ebp;
    decomp_var_4c = ebx;
    decomp_var_50 = esi;
    esi = arg_0;
    esp = esp - 0xc;
    decomp_var_54 = edi;
    var_2C = 0x0;
    var_24 = 0x0;
    var_1C = 0x0;
    var_28 = 0x0;
    var_20 = 0x0;
    var_48 = esi;
    if (esi[0x5] != 0x0) {
            eax = esi + 0x4;
            if (*eax == 0x0) {
                    ebx = 0x0;
                    esp = (esp - 0x14) + 0x14;
                    if (sub_4896f8() == 0x0) {
                            var_2C = sub_481280(0x4);
                            var_24 = sub_4812c0(0x180, 0x2);
                            var_1C = sub_4812c0(0x180, 0x1);
                            var_28 = sub_4812c0(0x180, 0x1);
                            eax = sub_4812c0(0x101, 0x1);
                            esp = (esp - 0x24) + 0x24;
                            var_20 = eax;
                            if (var_2C != ebx) {
                                    if (var_24 != ebx) {
                                            if (eax != ebx) {
                                                    ebx = 0x0;
                                                    if (var_1C != 0x0) {
                                                            if (var_28 != ebx) {
                                                                    *var_2C = ebx;
                                                                    eax = 0x0;
                                                                    do {
                                                                            *(int8_t *)(eax + var_20) = eax;
                                                                            eax = eax + 0x1;
                                                                    } while (eax < 0x100);
                                                                    esp = esp - 0x8;
                                                                    eax = GetCPInfo(esi[0x1], &var_18);
                                                                    if (eax != 0x0) {
                                                                            if (var_18 <= 0x5) {
                                                                                    var_30 = var_18 & 0xffff;
                                                                                    if ((var_18 & 0xffff) > 0x1 && var_12 != 0x0) {
                                                                                            eax = &var_11;
                                                                                            while (true) {
                                                                                                    ecx = *(int8_t *)eax;
                                                                                                    if (ecx == 0x0) {
                                                                                                            temp_1 = 0x1;
                                                                                                            break;
                                                                                                    }
                                                                                                    edi = *(int8_t *)(eax - 0x1) & 0xff;
                                                                                                    ecx = ecx & 0xff;
                                                                                                    while (edi <= ecx) {
                                                                                                            *(int8_t *)(edi + var_20) = 0x20;
                                                                                                            ecx = *(int8_t *)eax & 0xff;
                                                                                                            edi = edi + 0x1;
                                                                                                    }
                                                                                                    eax = eax + 0x2;
                                                                                                    if (*(int8_t *)(eax - 0x1) != 0x0) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    ebx = 0x0;
                                                                                    var_3C = var_24 + 0x100;
                                                                                    esp = (esp - 0x20) + 0x20;
                                                                                    if (sub_48ac1f(0x0, 0x1, var_20, 0x100, var_24 + 0x100, esi[0x1], 0x0, 0x0) != 0x0) {
                                                                                            esp = (esp - 0x24) + 0x24;
                                                                                            if (sub_482d50(ebx, esi[0x5], 0x100, var_20 + 0x1, 0xff, var_1C + 0x81, 0xff, esi[0x1], ebx) != 0x0) {
                                                                                                    ebx = 0x0;
                                                                                                    esp = (esp - 0x24) + 0x24;
                                                                                                    if (sub_482d50(0x0, esi[0x5], 0x200, var_20 + 0x1, 0xff, var_28 + 0x81, 0xff, esi[0x1], 0x0) != 0x0) {
                                                                                                            eax = var_24;
                                                                                                            edi = var_1C;
                                                                                                            eax[0x7f] = ebx;
                                                                                                            var_38 = eax + 0xfe;
                                                                                                            edi[0x7f] = ebx;
                                                                                                            var_28[0x7f] = ebx;
                                                                                                            edi[0x80] = ebx;
                                                                                                            var_40 = edi + 0x80;
                                                                                                            var_34 = var_28 + 0x80;
                                                                                                            var_28[0x80] = ebx;
                                                                                                            if (var_30 > 0x1 && var_12 != ebx) {
                                                                                                                    ecx = &var_11;
                                                                                                                    var_1C = ecx;
                                                                                                                    while (true) {
                                                                                                                            edx = *(int8_t *)ecx;
                                                                                                                            if (edx == ebx) {
                                                                                                                                    temp_0 = 0x1;
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                            ecx = *(int8_t *)(ecx - 0x1) & 0xff;
                                                                                                                            if (ecx <= (edx & 0xff)) {
                                                                                                                                    edx = eax + ecx * 0x2 + 0x100;
                                                                                                                                    while (true) {
                                                                                                                                            *(int16_t *)edx = 0x8000;
                                                                                                                                            ecx = ecx + 0x1;
                                                                                                                                            var_24 = edx + 0x2;
                                                                                                                                            if (ecx > (*(int8_t *)var_1C & 0xff)) {
                                                                                                                                                    break;
                                                                                                                                            }
                                                                                                                                            edx = var_24;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            ecx = var_1C + 0x2;
                                                                                                                            var_1C = ecx;
                                                                                                                            if (*(int8_t *)(ecx - 0x1) != ebx) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            temp_0 = 0x0;
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            sub_47c000(eax, eax + 0x200, 0xfe);
                                                                                                            sub_47c000(edi, edi + 0x100, 0x7f);
                                                                                                            sub_47c000(var_28, var_28 + 0x100, 0x7f);
                                                                                                            eax = esi[0x30];
                                                                                                            esp = (esp - 0x24) + 0x24;
                                                                                                            if (eax != ebx) {
                                                                                                                    esp = esp - 0x4;
                                                                                                                    if (InterlockedDecrement(eax) == 0x0) {
                                                                                                                            sub_47c8f9();
                                                                                                                            sub_47c8f9();
                                                                                                                            sub_47c8f9();
                                                                                                                            sub_47c8f9();
                                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                                    }
                                                                                                            }
                                                                                                            *var_2C = 0x1;
                                                                                                            esi[0x30] = var_2C;
                                                                                                            esi[0x32] = var_3C;
                                                                                                            esi[0x31] = var_38;
                                                                                                            esi[0x33] = var_40;
                                                                                                            esi[0x34] = var_34;
                                                                                                            esi[0x2b] = var_30;
                                                                                                            sub_47c8f9();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            eax = sub_47ad69();
                                                                                                    }
                                                                                                    else {
                                                                                                            sub_47c8f9();
                                                                                                            sub_47c8f9();
                                                                                                            sub_47c8f9();
                                                                                                            sub_47c8f9();
                                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                                            sub_47c8f9();
                                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                                            eax = sub_47ad69();
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    sub_47c8f9();
                                                                                                    sub_47c8f9();
                                                                                                    sub_47c8f9();
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    eax = sub_47ad69();
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            sub_47c8f9();
                                                                                            sub_47c8f9();
                                                                                            sub_47c8f9();
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            eax = sub_47ad69();
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_47c8f9();
                                                                                    sub_47c8f9();
                                                                                    sub_47c8f9();
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            esp = (esp - 0x10) + 0x10;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x10) + 0x10;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            esp = (esp - 0x10) + 0x10;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    esp = (esp - 0x10) + 0x10;
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            sub_47c8f9();
                            sub_47c8f9();
                            sub_47c8f9();
                            sub_47c8f9();
                            esp = (esp - 0x10) + 0x10;
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                            eax = sub_47ad69();
                    }
            }
            else {
                    var_2C = sub_481280(0x4);
                    var_24 = sub_4812c0(0x180, 0x2);
                    var_1C = sub_4812c0(0x180, 0x1);
                    var_28 = sub_4812c0(0x180, 0x1);
                    eax = sub_4812c0(0x101, 0x1);
                    esp = (esp - 0x24) + 0x24;
                    var_20 = eax;
                    if (var_2C != 0x0) {
                            ebx = 0x0;
                            if (var_24 != 0x0) {
                                    if (eax != ebx) {
                                            if (var_1C != 0x0) {
                                                    if (var_28 != 0x0) {
                                                            ebx = 0x0;
                                                            *var_2C = 0x0;
                                                            eax = 0x0;
                                                            do {
                                                                    *(int8_t *)(eax + var_20) = eax;
                                                                    eax = eax + 0x1;
                                                            } while (eax < 0x100);
                                                            esp = esp - 0x8;
                                                            eax = GetCPInfo(esi[0x1], &var_18);
                                                            if (eax != 0x0) {
                                                                    if (var_18 <= 0x5) {
                                                                            var_30 = var_18 & 0xffff;
                                                                            if ((var_18 & 0xffff) > 0x1 && var_12 != ebx) {
                                                                                    eax = &var_11;
                                                                                    while (true) {
                                                                                            ecx = *(int8_t *)eax;
                                                                                            if (ecx == ebx) {
                                                                                                    temp_1 = 0x1;
                                                                                                    break;
                                                                                            }
                                                                                            edi = *(int8_t *)(eax - 0x1) & 0xff;
                                                                                            ecx = ecx & 0xff;
                                                                                            while (edi <= ecx) {
                                                                                                    *(int8_t *)(edi + var_20) = 0x20;
                                                                                                    ecx = *(int8_t *)eax & 0xff;
                                                                                                    edi = edi + 0x1;
                                                                                            }
                                                                                            eax = eax + 0x2;
                                                                                            if (*(int8_t *)(eax - 0x1) != ebx) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            var_3C = var_24 + 0x100;
                                                                            esp = (esp - 0x20) + 0x20;
                                                                            if (sub_48ac1f(ebx, 0x1, var_20, 0x100, var_24 + 0x100, esi[0x1], ebx, ebx) != 0x0) {
                                                                                    esp = (esp - 0x24) + 0x24;
                                                                                    if (sub_482d50(ebx, esi[0x5], 0x100, var_20 + 0x1, 0xff, var_1C + 0x81, 0xff, esi[0x1], ebx) != 0x0) {
                                                                                            ebx = 0x0;
                                                                                            esp = (esp - 0x24) + 0x24;
                                                                                            if (sub_482d50(0x0, esi[0x5], 0x200, var_20 + 0x1, 0xff, var_28 + 0x81, 0xff, esi[0x1], 0x0) != 0x0) {
                                                                                                    eax = var_24;
                                                                                                    edi = var_1C;
                                                                                                    eax[0x7f] = ebx;
                                                                                                    var_38 = eax + 0xfe;
                                                                                                    edi[0x7f] = ebx;
                                                                                                    var_28[0x7f] = ebx;
                                                                                                    edi[0x80] = ebx;
                                                                                                    var_40 = edi + 0x80;
                                                                                                    var_34 = var_28 + 0x80;
                                                                                                    var_28[0x80] = ebx;
                                                                                                    if (var_30 > 0x1 && var_12 != ebx) {
                                                                                                            ecx = &var_11;
                                                                                                            var_1C = ecx;
                                                                                                            while (true) {
                                                                                                                    edx = *(int8_t *)ecx;
                                                                                                                    if (edx == ebx) {
                                                                                                                            temp_0 = 0x1;
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    ecx = *(int8_t *)(ecx - 0x1) & 0xff;
                                                                                                                    if (ecx <= (edx & 0xff)) {
                                                                                                                            edx = eax + ecx * 0x2 + 0x100;
                                                                                                                            while (true) {
                                                                                                                                    *(int16_t *)edx = 0x8000;
                                                                                                                                    ecx = ecx + 0x1;
                                                                                                                                    var_24 = edx + 0x2;
                                                                                                                                    if (ecx > (*(int8_t *)var_1C & 0xff)) {
                                                                                                                                            break;
                                                                                                                                    }
                                                                                                                                    edx = var_24;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = var_1C + 0x2;
                                                                                                                    var_1C = ecx;
                                                                                                                    if (*(int8_t *)(ecx - 0x1) != ebx) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    temp_0 = 0x0;
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    sub_47c000(eax, eax + 0x200, 0xfe);
                                                                                                    sub_47c000(edi, edi + 0x100, 0x7f);
                                                                                                    sub_47c000(var_28, var_28 + 0x100, 0x7f);
                                                                                                    eax = esi[0x30];
                                                                                                    esp = (esp - 0x24) + 0x24;
                                                                                                    if (eax != ebx) {
                                                                                                            esp = esp - 0x4;
                                                                                                            if (InterlockedDecrement(eax) == 0x0) {
                                                                                                                    sub_47c8f9();
                                                                                                                    sub_47c8f9();
                                                                                                                    sub_47c8f9();
                                                                                                                    sub_47c8f9();
                                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                            }
                                                                                                    }
                                                                                                    *var_2C = 0x1;
                                                                                                    esi[0x30] = var_2C;
                                                                                                    esi[0x32] = var_3C;
                                                                                                    esi[0x31] = var_38;
                                                                                                    esi[0x33] = var_40;
                                                                                                    esi[0x34] = var_34;
                                                                                                    esi[0x2b] = var_30;
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    eax = sub_47ad69();
                                                                                            }
                                                                                            else {
                                                                                                    sub_47c8f9();
                                                                                                    sub_47c8f9();
                                                                                                    sub_47c8f9();
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                                    sub_47c8f9();
                                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                                    eax = sub_47ad69();
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            sub_47c8f9();
                                                                                            sub_47c8f9();
                                                                                            sub_47c8f9();
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x10) + 0x10;
                                                                                            sub_47c8f9();
                                                                                            esp = (esp - 0x4) + 0x4;
                                                                                            eax = sub_47ad69();
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    sub_47c8f9();
                                                                                    sub_47c8f9();
                                                                                    sub_47c8f9();
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x10) + 0x10;
                                                                                    sub_47c8f9();
                                                                                    esp = (esp - 0x4) + 0x4;
                                                                                    eax = sub_47ad69();
                                                                            }
                                                                    }
                                                                    else {
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x10) + 0x10;
                                                                            sub_47c8f9();
                                                                            esp = (esp - 0x4) + 0x4;
                                                                            eax = sub_47ad69();
                                                                    }
                                                            }
                                                            else {
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x10) + 0x10;
                                                                    sub_47c8f9();
                                                                    esp = (esp - 0x4) + 0x4;
                                                                    eax = sub_47ad69();
                                                            }
                                                    }
                                                    else {
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            sub_47c8f9();
                                                            esp = (esp - 0x10) + 0x10;
                                                            sub_47c8f9();
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = sub_47ad69();
                                                    }
                                            }
                                            else {
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    sub_47c8f9();
                                                    esp = (esp - 0x10) + 0x10;
                                                    sub_47c8f9();
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = sub_47ad69();
                                            }
                                    }
                                    else {
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            sub_47c8f9();
                                            esp = (esp - 0x10) + 0x10;
                                            sub_47c8f9();
                                            esp = (esp - 0x4) + 0x4;
                                            eax = sub_47ad69();
                                    }
                            }
                            else {
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    sub_47c8f9();
                                    esp = (esp - 0x10) + 0x10;
                                    sub_47c8f9();
                                    esp = (esp - 0x4) + 0x4;
                                    eax = sub_47ad69();
                            }
                    }
                    else {
                            sub_47c8f9();
                            sub_47c8f9();
                            sub_47c8f9();
                            sub_47c8f9();
                            esp = (esp - 0x10) + 0x10;
                            sub_47c8f9();
                            esp = (esp - 0x4) + 0x4;
                            eax = sub_47ad69();
                    }
            }
    }
    else {
            edi = esi + 0xc0;
            eax = *edi;
            if (eax != 0x0) {
                    esp = esp - 0x4;
                    InterlockedDecrement(eax);
            }
            *edi = 0x0;
            esi[0x31] = 0x0;
            esi[0x32] = 0x4b8458;
            esi[0x33] = 0x4b88e0;
            esi[0x34] = 0x4b8a60;
            esi[0x2b] = 0x1;
            eax = sub_47ad69();
    }
    return eax;
}
