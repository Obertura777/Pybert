// sub_48fa60 @ 0x48fa60
// hopper name: sub_48fa60
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48fa60() {
    decomp_var_4 = ebx;
    decomp_var_8 = ebp;
    decomp_var_c = esi;
    esi = arg_4;
    ebp = ebp | 0xffffffff;
    esp = esp - 0x10;
    decomp_var_10 = edi;
    if ((esi[0xc] & 0x40) == 0x0) {
            esp = (esp - 0x4) + 0x4;
            if (sub_4867ae(esi) != ebp) {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_4867ae(esi) != 0xfffffffe) {
                            edi = (SAR(sub_4867ae(esi), 0x5)) * 0x4 + dword_bc7240;
                            eax = sub_4867ae(esi);
                            eax = (eax & 0x1f) * 0x28 + *edi;
                            esp = (esp - 0x8) + 0x8;
                    }
                    else {
                            eax = 0x4c9958;
                    }
            }
            else {
                    eax = 0x4c9958;
            }
            if ((eax[0x24] & 0x7f) == 0x0) {
                    esp = (esp - 0x4) + 0x4;
                    if (sub_4867ae(esi) != ebp) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_4867ae(esi) != 0xfffffffe) {
                                    edi = (SAR(sub_4867ae(esi), 0x5)) * 0x4 + dword_bc7240;
                                    eax = sub_4867ae(esi);
                                    eax = (eax & 0x1f) * 0x28 + *edi;
                                    esp = (esp - 0x8) + 0x8;
                            }
                            else {
                                    eax = 0x4c9958;
                            }
                    }
                    else {
                            eax = 0x4c9958;
                    }
                    if ((eax[0x24] & 0x80) != 0x0) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = ebp;
                    }
                    else {
                            ebx = arg_0;
                            if (ebx != ebp) {
                                    eax = esi[0x3];
                                    if ((eax & 0x1) == 0x0) {
                                            if (eax < 0x0) {
                                                    if ((eax & 0x2) == 0x0) {
                                                            if (esi[0x2] == 0x0) {
                                                                    sub_48e10c(esi);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            eax = *esi;
                                                            if (eax == esi[0x2]) {
                                                                    if (esi[0x1] == 0x0) {
                                                                            *esi = eax + 0x1;
                                                                            *esi = *esi - 0x1;
                                                                            bool_32 = (esi[0xc] & 0x40) == 0x0;
                                                                            eax = *esi;
                                                                            if (!bool_32) {
                                                                                    if (*(int8_t *)eax != ebx) {
                                                                                            *esi = eax + 0x1;
                                                                                            eax = ebp;
                                                                                    }
                                                                                    else {
                                                                                            eax = esi[0x3];
                                                                                            esi[0x1] = esi[0x1] + 0x1;
                                                                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                                                                            eax = ebx & 0xff;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    *(int8_t *)eax = ebx;
                                                                                    eax = esi[0x3];
                                                                                    esi[0x1] = esi[0x1] + 0x1;
                                                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                                                    eax = ebx & 0xff;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = ebp;
                                                                    }
                                                            }
                                                            else {
                                                                    *esi = *esi - 0x1;
                                                                    bool_42 = (esi[0xc] & 0x40) == 0x0;
                                                                    eax = *esi;
                                                                    if (!bool_42) {
                                                                            if (*(int8_t *)eax != ebx) {
                                                                                    *esi = eax + 0x1;
                                                                                    eax = ebp;
                                                                            }
                                                                            else {
                                                                                    eax = esi[0x3];
                                                                                    esi[0x1] = esi[0x1] + 0x1;
                                                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                                                    eax = ebx & 0xff;
                                                                            }
                                                                    }
                                                                    else {
                                                                            *(int8_t *)eax = ebx;
                                                                            eax = esi[0x3];
                                                                            esi[0x1] = esi[0x1] + 0x1;
                                                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                                                            eax = ebx & 0xff;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            eax = ebp;
                                                    }
                                            }
                                            else {
                                                    eax = ebp;
                                            }
                                    }
                                    else {
                                            if (esi[0x2] == 0x0) {
                                                    sub_48e10c(esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            eax = *esi;
                                            if (eax == esi[0x2]) {
                                                    if (esi[0x1] == 0x0) {
                                                            *esi = eax + 0x1;
                                                            *esi = *esi - 0x1;
                                                            bool_33 = (esi[0xc] & 0x40) == 0x0;
                                                            eax = *esi;
                                                            if (!bool_33) {
                                                                    if (*(int8_t *)eax != ebx) {
                                                                            *esi = eax + 0x1;
                                                                            eax = ebp;
                                                                    }
                                                                    else {
                                                                            eax = esi[0x3];
                                                                            esi[0x1] = esi[0x1] + 0x1;
                                                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                                                            eax = ebx & 0xff;
                                                                    }
                                                            }
                                                            else {
                                                                    *(int8_t *)eax = ebx;
                                                                    eax = esi[0x3];
                                                                    esi[0x1] = esi[0x1] + 0x1;
                                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                                    eax = ebx & 0xff;
                                                            }
                                                    }
                                                    else {
                                                            eax = ebp;
                                                    }
                                            }
                                            else {
                                                    *esi = *esi - 0x1;
                                                    bool_25 = (esi[0xc] & 0x40) == 0x0;
                                                    eax = *esi;
                                                    if (!bool_25) {
                                                            if (*(int8_t *)eax != ebx) {
                                                                    *esi = eax + 0x1;
                                                                    eax = ebp;
                                                            }
                                                            else {
                                                                    eax = esi[0x3];
                                                                    esi[0x1] = esi[0x1] + 0x1;
                                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                                    eax = ebx & 0xff;
                                                            }
                                                    }
                                                    else {
                                                            *(int8_t *)eax = ebx;
                                                            eax = esi[0x3];
                                                            esi[0x1] = esi[0x1] + 0x1;
                                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                                            eax = ebx & 0xff;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    eax = ebp;
                            }
                    }
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    eax = ebp;
            }
    }
    else {
            ebx = arg_0;
            if (ebx != ebp) {
                    eax = esi[0x3];
                    if ((eax & 0x1) == 0x0) {
                            if (eax < 0x0) {
                                    if ((eax & 0x2) == 0x0) {
                                            if (esi[0x2] == 0x0) {
                                                    sub_48e10c(esi);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            eax = *esi;
                                            if (eax == esi[0x2]) {
                                                    if (esi[0x1] == 0x0) {
                                                            *esi = eax + 0x1;
                                                            *esi = *esi - 0x1;
                                                            bool_5 = (esi[0xc] & 0x40) == 0x0;
                                                            eax = *esi;
                                                            if (!bool_5) {
                                                                    if (*(int8_t *)eax != ebx) {
                                                                            *esi = eax + 0x1;
                                                                            eax = ebp;
                                                                    }
                                                                    else {
                                                                            eax = esi[0x3];
                                                                            esi[0x1] = esi[0x1] + 0x1;
                                                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                                                            eax = ebx & 0xff;
                                                                    }
                                                            }
                                                            else {
                                                                    *(int8_t *)eax = ebx;
                                                                    eax = esi[0x3];
                                                                    esi[0x1] = esi[0x1] + 0x1;
                                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                                    eax = ebx & 0xff;
                                                            }
                                                    }
                                                    else {
                                                            eax = ebp;
                                                    }
                                            }
                                            else {
                                                    *esi = *esi - 0x1;
                                                    bool_8 = (esi[0xc] & 0x40) == 0x0;
                                                    eax = *esi;
                                                    if (!bool_8) {
                                                            if (*(int8_t *)eax != ebx) {
                                                                    *esi = eax + 0x1;
                                                                    eax = ebp;
                                                            }
                                                            else {
                                                                    eax = esi[0x3];
                                                                    esi[0x1] = esi[0x1] + 0x1;
                                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                                    eax = ebx & 0xff;
                                                            }
                                                    }
                                                    else {
                                                            *(int8_t *)eax = ebx;
                                                            eax = esi[0x3];
                                                            esi[0x1] = esi[0x1] + 0x1;
                                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                                            eax = ebx & 0xff;
                                                    }
                                            }
                                    }
                                    else {
                                            eax = ebp;
                                    }
                            }
                            else {
                                    eax = ebp;
                            }
                    }
                    else {
                            if (esi[0x2] == 0x0) {
                                    sub_48e10c(esi);
                                    esp = (esp - 0x4) + 0x4;
                            }
                            eax = *esi;
                            if (eax == esi[0x2]) {
                                    if (esi[0x1] == 0x0) {
                                            *esi = eax + 0x1;
                                            *esi = *esi - 0x1;
                                            bool_6 = (esi[0xc] & 0x40) == 0x0;
                                            eax = *esi;
                                            if (!bool_6) {
                                                    if (*(int8_t *)eax != ebx) {
                                                            *esi = eax + 0x1;
                                                            eax = ebp;
                                                    }
                                                    else {
                                                            eax = esi[0x3];
                                                            esi[0x1] = esi[0x1] + 0x1;
                                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                                            eax = ebx & 0xff;
                                                    }
                                            }
                                            else {
                                                    *(int8_t *)eax = ebx;
                                                    eax = esi[0x3];
                                                    esi[0x1] = esi[0x1] + 0x1;
                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                    eax = ebx & 0xff;
                                            }
                                    }
                                    else {
                                            eax = ebp;
                                    }
                            }
                            else {
                                    *esi = *esi - 0x1;
                                    bool_17 = (esi[0xc] & 0x40) == 0x0;
                                    eax = *esi;
                                    if (!bool_17) {
                                            if (*(int8_t *)eax != ebx) {
                                                    *esi = eax + 0x1;
                                                    eax = ebp;
                                            }
                                            else {
                                                    eax = esi[0x3];
                                                    esi[0x1] = esi[0x1] + 0x1;
                                                    esi[0x3] = eax & 0xffffffef | 0x1;
                                                    eax = ebx & 0xff;
                                            }
                                    }
                                    else {
                                            *(int8_t *)eax = ebx;
                                            eax = esi[0x3];
                                            esi[0x1] = esi[0x1] + 0x1;
                                            esi[0x3] = eax & 0xffffffef | 0x1;
                                            eax = ebx & 0xff;
                                    }
                            }
                    }
            }
            else {
                    eax = ebp;
            }
    }
    return eax;
}
