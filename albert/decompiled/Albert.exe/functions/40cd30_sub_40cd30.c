// sub_40cd30 @ 0x40cd30
// hopper name: sub_40cd30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40cd30() {
    eax = arg_8;
    ecx = arg_4;
    edx = arg_0;
    decomp_var_4 = esi;
    esp = esp - 0x8;
    decomp_var_8 = edi;
    if (eax >= 0x4) {
            while (true) {
                    if (*edx != *ecx) {
                            temp_0 = 0x1;
                            break;
                    }
                    eax = eax - 0x4;
                    ecx = ecx + 0x4;
                    edx = edx + 0x4;
                    if (eax >= 0x4) {
                            continue;
                    }
                    temp_0 = 0x0;
                    break;
            }
            if (temp_0 != 0x0) {
                    esi = *(int8_t *)edx & 0xff;
                    esi = esi - (*(int8_t *)ecx & 0xff);
                    if (esi == 0x0) {
                            eax = eax - 0x1;
                            ecx = ecx + 0x1;
                            edx = edx + 0x1;
                            if (eax != 0x0) {
                                    esi = *(int8_t *)edx & 0xff;
                                    esi = esi - (*(int8_t *)ecx & 0xff);
                                    if (esi == 0x0) {
                                            eax = eax - 0x1;
                                            ecx = ecx + 0x1;
                                            edx = edx + 0x1;
                                            if (eax != 0x0) {
                                                    esi = *(int8_t *)edx & 0xff;
                                                    esi = esi - (*(int8_t *)ecx & 0xff);
                                                    if (esi == 0x0) {
                                                            ecx = ecx + 0x1;
                                                            edx = edx + 0x1;
                                                            if (eax != 0x1) {
                                                                    esi = *(int8_t *)edx & 0xff;
                                                                    esi = esi - (*(int8_t *)ecx & 0xff);
                                                                    if (esi != 0x0) {
                                                                            eax = 0x1;
                                                                            if (esi <= 0x0) {
                                                                                    eax = 0xffffffff;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                            if (esi <= 0x0) {
                                                                    eax = 0xffffffff;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x1;
                                            if (esi <= 0x0) {
                                                    eax = 0xffffffff;
                                            }
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x1;
                            if (esi <= 0x0) {
                                    eax = 0xffffffff;
                            }
                    }
            }
            else {
                    if (eax != 0x0) {
                            esi = *(int8_t *)edx & 0xff;
                            esi = esi - (*(int8_t *)ecx & 0xff);
                            if (esi == 0x0) {
                                    eax = eax - 0x1;
                                    ecx = ecx + 0x1;
                                    edx = edx + 0x1;
                                    if (eax != 0x0) {
                                            esi = *(int8_t *)edx & 0xff;
                                            esi = esi - (*(int8_t *)ecx & 0xff);
                                            if (esi == 0x0) {
                                                    eax = eax - 0x1;
                                                    ecx = ecx + 0x1;
                                                    edx = edx + 0x1;
                                                    if (eax != 0x0) {
                                                            esi = *(int8_t *)edx & 0xff;
                                                            esi = esi - (*(int8_t *)ecx & 0xff);
                                                            if (esi == 0x0) {
                                                                    ecx = ecx + 0x1;
                                                                    edx = edx + 0x1;
                                                                    if (eax != 0x1) {
                                                                            esi = *(int8_t *)edx & 0xff;
                                                                            esi = esi - (*(int8_t *)ecx & 0xff);
                                                                            if (esi != 0x0) {
                                                                                    eax = 0x1;
                                                                                    if (esi <= 0x0) {
                                                                                            eax = 0xffffffff;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = 0x0;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                                    if (esi <= 0x0) {
                                                                            eax = 0xffffffff;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x1;
                                                    if (esi <= 0x0) {
                                                            eax = 0xffffffff;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x1;
                                    if (esi <= 0x0) {
                                            eax = 0xffffffff;
                                    }
                            }
                    }
                    else {
                            eax = 0x0;
                    }
            }
    }
    else {
            if (eax != 0x0) {
                    esi = *(int8_t *)edx & 0xff;
                    esi = esi - (*(int8_t *)ecx & 0xff);
                    if (esi == 0x0) {
                            eax = eax - 0x1;
                            ecx = ecx + 0x1;
                            edx = edx + 0x1;
                            if (eax != 0x0) {
                                    esi = *(int8_t *)edx & 0xff;
                                    esi = esi - (*(int8_t *)ecx & 0xff);
                                    if (esi == 0x0) {
                                            eax = eax - 0x1;
                                            ecx = ecx + 0x1;
                                            edx = edx + 0x1;
                                            if (eax != 0x0) {
                                                    esi = *(int8_t *)edx & 0xff;
                                                    esi = esi - (*(int8_t *)ecx & 0xff);
                                                    if (esi == 0x0) {
                                                            ecx = ecx + 0x1;
                                                            edx = edx + 0x1;
                                                            if (eax != 0x1) {
                                                                    esi = *(int8_t *)edx & 0xff;
                                                                    esi = esi - (*(int8_t *)ecx & 0xff);
                                                                    if (esi != 0x0) {
                                                                            eax = 0x1;
                                                                            if (esi <= 0x0) {
                                                                                    eax = 0xffffffff;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = 0x0;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                            if (esi <= 0x0) {
                                                                    eax = 0xffffffff;
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x1;
                                            if (esi <= 0x0) {
                                                    eax = 0xffffffff;
                                            }
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
                    else {
                            eax = 0x1;
                            if (esi <= 0x0) {
                                    eax = 0xffffffff;
                            }
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    return eax;
}
