// sub_48c337 @ 0x48c337
// hopper name: sub_48c337
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48c337() {
    var_4 = var_4 & 0x0;
    esp = esp - 0x4;
    decomp_var_8 = ebx;
    ebx = arg_8;
    if (ebx == 0x0) {
            eax = 0x0;
    }
    else {
            esp = esp - 0x4;
            decomp_var_c = edi;
            if (ebx >= 0x4) {
                    edi = ebx - 0x4;
                    if (edi > 0x0) {
                            ecx = arg_4;
                            eax = arg_0;
                            while (true) {
                                    edx = *(int8_t *)eax;
                                    eax = eax + 0x4;
                                    ecx = ecx + 0x4;
                                    if (edx == 0x0) {
                                            temp_0 = 0x4;
                                            break;
                                    }
                                    if (edx != *(int8_t *)(ecx - 0x4)) {
                                            temp_0 = 0x4;
                                            break;
                                    }
                                    edx = *(int8_t *)(eax - 0x3);
                                    if (edx == 0x0) {
                                            temp_0 = 0x3;
                                            break;
                                    }
                                    if (edx != *(int8_t *)(ecx - 0x3)) {
                                            temp_0 = 0x3;
                                            break;
                                    }
                                    edx = *(int8_t *)(eax - 0x2);
                                    if (edx == 0x0) {
                                            temp_0 = 0x2;
                                            break;
                                    }
                                    if (edx != *(int8_t *)(ecx - 0x2)) {
                                            temp_0 = 0x2;
                                            break;
                                    }
                                    edx = *(int8_t *)(eax - 0x1);
                                    if (edx == 0x0) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    if (edx != *(int8_t *)(ecx - 0x1)) {
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    var_4 = var_4 + 0x4;
                                    if (var_4 < edi) {
                                            continue;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (temp_0 != 0x0) {
                                    switch (temp_0) {
                                        case 1:
                                            eax = *(int8_t *)(eax - 0x1) & 0xff;
                                            ecx = *(int8_t *)(ecx - 0x1) & 0xff;
                                            break;
                                        case 2:
                                            eax = *(int8_t *)(eax - 0x2) & 0xff;
                                            ecx = *(int8_t *)(ecx - 0x2) & 0xff;
                                            break;
                                        case 3:
                                            eax = *(int8_t *)(eax - 0x3) & 0xff;
                                            ecx = *(int8_t *)(ecx - 0x3) & 0xff;
                                            break;
                                        default:
                                            eax = *(int8_t *)(eax - 0x4) & 0xff;
                                            ecx = *(int8_t *)(ecx - 0x4) & 0xff;
                                            break;
                                    }
                                    eax = eax - ecx;
                                    esp = esp + 0x4;
                            }
                            else {
                                    while (true) {
                                            if (var_4 >= ebx) {
                                                    eax = 0x0;
                                                    temp_1 = 0x0;
                                                    break;
                                            }
                                            else {
                                                    edx = *(int8_t *)eax;
                                                    if (edx != 0x0) {
                                                            if (edx == *(int8_t *)ecx) {
                                                                    eax = eax + 0x1;
                                                                    ecx = ecx + 0x1;
                                                                    var_4 = var_4 + 0x1;
                                                                    continue;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                                    else {
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                            }
                                    }
                                    if (temp_1 != 0x0) {
                                            eax = *(int8_t *)eax & 0xff;
                                            ecx = *(int8_t *)ecx & 0xff;
                                            eax = eax - ecx;
                                    }
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            ecx = arg_4;
                            eax = arg_0;
                            while (true) {
                                    if (var_4 >= ebx) {
                                            eax = 0x0;
                                            temp_1 = 0x0;
                                            break;
                                    }
                                    else {
                                            edx = *(int8_t *)eax;
                                            if (edx != 0x0) {
                                                    if (edx == *(int8_t *)ecx) {
                                                            eax = eax + 0x1;
                                                            ecx = ecx + 0x1;
                                                            var_4 = var_4 + 0x1;
                                                            continue;
                                                    }
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_1 = 0x1;
                                                    break;
                                            }
                                    }
                            }
                            if (temp_1 != 0x0) {
                                    eax = *(int8_t *)eax & 0xff;
                                    ecx = *(int8_t *)ecx & 0xff;
                                    eax = eax - ecx;
                            }
                            esp = esp + 0x4;
                    }
            }
            else {
                    ecx = arg_4;
                    eax = arg_0;
                    while (true) {
                            if (var_4 >= ebx) {
                                    eax = 0x0;
                                    temp_1 = 0x0;
                                    break;
                            }
                            else {
                                    edx = *(int8_t *)eax;
                                    if (edx != 0x0) {
                                            if (edx == *(int8_t *)ecx) {
                                                    eax = eax + 0x1;
                                                    ecx = ecx + 0x1;
                                                    var_4 = var_4 + 0x1;
                                                    continue;
                                            }
                                            temp_1 = 0x1;
                                            break;
                                    }
                                    else {
                                            temp_1 = 0x1;
                                            break;
                                    }
                            }
                    }
                    if (temp_1 != 0x0) {
                            eax = *(int8_t *)eax & 0xff;
                            ecx = *(int8_t *)ecx & 0xff;
                            eax = eax - ecx;
                    }
                    esp = esp + 0x4;
            }
    }
    return eax;
}
