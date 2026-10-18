// sub_477240 @ 0x477240
// hopper name: sub_477240
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_477240() {
    esi = arg_8;
    ebx = ecx;
    esp = esp - 0xc;
    if ((*(*ebx + 0x44))() == 0x0) {
            esp = esp - 0x4;
            edi = (*(*ebx + 0x38))();
            if (0x0 == *esi) {
                    if (esi[0x1] == 0x0) {
                            if (esi[0x2] == 0xc0) {
                                    if (esi[0x3] == 0x46000000) {
                                            while (true) {
                                                    ecx = edi[0x1];
                                                    while (true) {
                                                            if (*ecx != 0x0) {
                                                                    if (*(ecx[0x1] + ebx) == 0x0) {
                                                                            ecx = ecx + 0x8;
                                                                            continue;
                                                                    }
                                                                    temp_1 = 0x0;
                                                                    break;
                                                            }
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                                    if (temp_1 == 0x0) {
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                                    edi = *edi;
                                                    if (edi != 0x0) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x1;
                                                    break;
                                            }
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            edx = edi[0x1];
                                            while (true) {
                                                    ecx = *edx;
                                                    if (ecx != 0x0) {
                                                            if (*ecx != *esi) {
                                                                    edx = edx + 0x8;
                                                                    continue;
                                                            }
                                                            if (ecx[0x1] != esi[0x1]) {
                                                                    edx = edx + 0x8;
                                                                    continue;
                                                            }
                                                            if (ecx[0x2] != esi[0x2]) {
                                                                    edx = edx + 0x8;
                                                                    continue;
                                                            }
                                                            if (ecx[0x3] != esi[0x3]) {
                                                                    edx = edx + 0x8;
                                                                    continue;
                                                            }
                                                            if (*(edx[0x1] + ebx) == 0x0) {
                                                                    edx = edx + 0x8;
                                                                    continue;
                                                            }
                                                            temp_0 = 0x1;
                                                            break;
                                                    }
                                                    temp_0 = 0x0;
                                                    break;
                                            }
                                            if (temp_0 != 0x0) {
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    edi = *edi;
                                                    if (edi == 0x0) {
                                                            esp = esp + 0x4;
                                                    }
                                                    else {
                                                            while (true) {
                                                                    edx = edi[0x1];
                                                                    while (true) {
                                                                            ecx = *edx;
                                                                            if (ecx != 0x0) {
                                                                                    if (*ecx != *esi) {
                                                                                            edx = edx + 0x8;
                                                                                            continue;
                                                                                    }
                                                                                    if (ecx[0x1] != esi[0x1]) {
                                                                                            edx = edx + 0x8;
                                                                                            continue;
                                                                                    }
                                                                                    if (ecx[0x2] != esi[0x2]) {
                                                                                            edx = edx + 0x8;
                                                                                            continue;
                                                                                    }
                                                                                    if (ecx[0x3] != esi[0x3]) {
                                                                                            edx = edx + 0x8;
                                                                                            continue;
                                                                                    }
                                                                                    if (*(edx[0x1] + ebx) == 0x0) {
                                                                                            edx = edx + 0x8;
                                                                                            continue;
                                                                                    }
                                                                                    temp_0 = 0x1;
                                                                                    break;
                                                                            }
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    if (temp_0 == 0x0) {
                                                                            edi = *edi;
                                                                            if (edi != 0x0) {
                                                                                    continue;
                                                                            }
                                                                            temp_2 = 0x0;
                                                                            break;
                                                                    }
                                                                    temp_2 = 0x1;
                                                                    break;
                                                            }
                                                            if (temp_2 == 0x0) goto loc_4772e6;
                                                            esp = esp + 0x4;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    edx = edi[0x1];
                                    while (true) {
                                            ecx = *edx;
                                            if (ecx != 0x0) {
                                                    if (*ecx != *esi) {
                                                            edx = edx + 0x8;
                                                            continue;
                                                    }
                                                    if (ecx[0x1] != esi[0x1]) {
                                                            edx = edx + 0x8;
                                                            continue;
                                                    }
                                                    if (ecx[0x2] != esi[0x2]) {
                                                            edx = edx + 0x8;
                                                            continue;
                                                    }
                                                    if (ecx[0x3] != esi[0x3]) {
                                                            edx = edx + 0x8;
                                                            continue;
                                                    }
                                                    if (*(edx[0x1] + ebx) == 0x0) {
                                                            edx = edx + 0x8;
                                                            continue;
                                                    }
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                                    if (temp_0 != 0x0) {
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            edi = *edi;
                                            if (edi == 0x0) {
                                                    esp = esp + 0x4;
                                            }
                                            else {
                                                    while (true) {
                                                            edx = edi[0x1];
                                                            while (true) {
                                                                    ecx = *edx;
                                                                    if (ecx != 0x0) {
                                                                            if (*ecx != *esi) {
                                                                                    edx = edx + 0x8;
                                                                                    continue;
                                                                            }
                                                                            if (ecx[0x1] != esi[0x1]) {
                                                                                    edx = edx + 0x8;
                                                                                    continue;
                                                                            }
                                                                            if (ecx[0x2] != esi[0x2]) {
                                                                                    edx = edx + 0x8;
                                                                                    continue;
                                                                            }
                                                                            if (ecx[0x3] != esi[0x3]) {
                                                                                    edx = edx + 0x8;
                                                                                    continue;
                                                                            }
                                                                            if (*(edx[0x1] + ebx) == 0x0) {
                                                                                    edx = edx + 0x8;
                                                                                    continue;
                                                                            }
                                                                            temp_0 = 0x1;
                                                                            break;
                                                                    }
                                                                    temp_0 = 0x0;
                                                                    break;
                                                            }
                                                            if (temp_0 == 0x0) {
                                                                    edi = *edi;
                                                                    if (edi != 0x0) {
                                                                            continue;
                                                                    }
                                                                    temp_2 = 0x0;
                                                                    break;
                                                            }
                                                            temp_2 = 0x1;
                                                            break;
                                                    }
                                                    if (temp_2 == 0x0) goto loc_4772e6;
                                                    esp = esp + 0x4;
                                            }
                                    }
                            }
                    }
                    else {
                            edx = edi[0x1];
                            while (true) {
                                    ecx = *edx;
                                    if (ecx != 0x0) {
                                            if (*ecx != *esi) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (ecx[0x1] != esi[0x1]) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (ecx[0x2] != esi[0x2]) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (ecx[0x3] != esi[0x3]) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (*(edx[0x1] + ebx) == 0x0) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (temp_0 != 0x0) {
                                    esp = esp + 0x4;
                            }
                            else {
                                    edi = *edi;
                                    if (edi == 0x0) {
                                            esp = esp + 0x4;
                                    }
                                    else {
                                            while (true) {
                                                    edx = edi[0x1];
                                                    while (true) {
                                                            ecx = *edx;
                                                            if (ecx != 0x0) {
                                                                    if (*ecx != *esi) {
                                                                            edx = edx + 0x8;
                                                                            continue;
                                                                    }
                                                                    if (ecx[0x1] != esi[0x1]) {
                                                                            edx = edx + 0x8;
                                                                            continue;
                                                                    }
                                                                    if (ecx[0x2] != esi[0x2]) {
                                                                            edx = edx + 0x8;
                                                                            continue;
                                                                    }
                                                                    if (ecx[0x3] != esi[0x3]) {
                                                                            edx = edx + 0x8;
                                                                            continue;
                                                                    }
                                                                    if (*(edx[0x1] + ebx) == 0x0) {
                                                                            edx = edx + 0x8;
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            temp_0 = 0x0;
                                                            break;
                                                    }
                                                    if (temp_0 == 0x0) {
                                                            edi = *edi;
                                                            if (edi != 0x0) {
                                                                    continue;
                                                            }
                                                            temp_2 = 0x0;
                                                            break;
                                                    }
                                                    temp_2 = 0x1;
                                                    break;
                                            }
                                            if (temp_2 == 0x0) goto loc_4772e6;
                                            esp = esp + 0x4;
                                    }
                            }
                    }
            }
            else {
                    while (true) {
                            edx = edi[0x1];
                            while (true) {
                                    ecx = *edx;
                                    if (ecx != 0x0) {
                                            if (*ecx != *esi) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (ecx[0x1] != esi[0x1]) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (ecx[0x2] != esi[0x2]) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (ecx[0x3] != esi[0x3]) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            if (*(edx[0x1] + ebx) == 0x0) {
                                                    edx = edx + 0x8;
                                                    continue;
                                            }
                                            temp_0 = 0x1;
                                            break;
                                    }
                                    temp_0 = 0x0;
                                    break;
                            }
                            if (temp_0 == 0x0) {
                                    edi = *edi;
                                    if (edi != 0x0) {
                                            continue;
                                    }
                                    temp_2 = 0x0;
                                    break;
                            }
                            temp_2 = 0x1;
                            break;
                    }
                    if (temp_2 == 0x0) goto loc_4772e6;
                    esp = esp + 0x4;
            }
    }
    return;
}
