// sub_48f344 @ 0x48f344
// hopper name: sub_48f344
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f344() {
    decomp_var_14 = ebx;
    esp = esp - 0x8;
    decomp_var_18 = esi;
    esi = arg_4;
    if (esi != 0x0) {
            if (arg_8 != 0x0) {
                    if (*(int8_t *)esi == 0x0) {
                            eax = arg_0;
                            if (eax != 0x0) {
                                    *(int16_t *)eax = 0x0;
                            }
                            eax = 0x0;
                    }
                    else {
                            esp = esp - 0x4;
                            sub_47aea2(arg_c);
                            if (var_10[0x5] == 0x0) {
                                    eax = arg_0;
                                    if (eax != 0x0) {
                                            *(int16_t *)eax = *(int8_t *)esi & 0xff;
                                    }
                                    if (var_4 != 0x0) {
                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x1;
                            }
                            else {
                                    eax = *(int8_t *)esi & 0xff;
                                    eax = sub_487c37(eax, &var_10);
                                    esp = (esp - 0x8) + 0x8;
                                    if (eax != 0x0) {
                                            eax = var_10;
                                            ecx = eax[0x2b];
                                            if (ecx > 0x1) {
                                                    if (arg_8 >= ecx) {
                                                            ebx = 0x0;
                                                            esp = esp - 0x18;
                                                            MultiByteToWideChar(eax[0x1], 0x9, esi, ecx, arg_0, arg_0 != 0x0 ? 0x1 : 0x0);
                                                            eax = var_10;
                                                            if (arg_0 == 0x0) {
                                                                    if (arg_8 >= eax[0x2b]) {
                                                                            ebx = 0x0;
                                                                            if (esi[0x1] != 0x0) {
                                                                                    eax = eax[0x2b];
                                                                                    if (var_4 != ebx) {
                                                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    eax = sub_47d812();
                                                                                    *eax = 0x2a;
                                                                                    if (var_4 != 0x0) {
                                                                                            eax = var_8;
                                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                                    }
                                                                                    eax = eax | 0xffffffff;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47d812();
                                                                            *eax = 0x2a;
                                                                            if (var_4 != ebx) {
                                                                                    eax = var_8;
                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                            }
                                                                            eax = eax | 0xffffffff;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = eax[0x2b];
                                                                    if (var_4 != ebx) {
                                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (arg_8 >= eax[0x2b]) {
                                                                    ebx = 0x0;
                                                                    if (esi[0x1] != 0x0) {
                                                                            eax = eax[0x2b];
                                                                            if (var_4 != ebx) {
                                                                                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                                            }
                                                                    }
                                                                    else {
                                                                            eax = sub_47d812();
                                                                            *eax = 0x2a;
                                                                            if (var_4 != ebx) {
                                                                                    eax = var_8;
                                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                            }
                                                                            eax = eax | 0xffffffff;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47d812();
                                                                    *eax = 0x2a;
                                                                    if (var_4 != 0x0) {
                                                                            eax = var_8;
                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                    }
                                                                    eax = eax | 0xffffffff;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (arg_8 >= eax[0x2b]) {
                                                            if (esi[0x1] != 0x0) {
                                                                    eax = eax[0x2b];
                                                                    if (var_4 != 0x0) {
                                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = sub_47d812();
                                                                    *eax = 0x2a;
                                                                    if (var_4 != 0x0) {
                                                                            eax = var_8;
                                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                                    }
                                                                    eax = eax | 0xffffffff;
                                                            }
                                                    }
                                                    else {
                                                            eax = sub_47d812();
                                                            *eax = 0x2a;
                                                            if (var_4 != 0x0) {
                                                                    eax = var_8;
                                                                    eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                            }
                                                            eax = eax | 0xffffffff;
                                                    }
                                            }
                                    }
                                    else {
                                            esp = esp - 0x18;
                                            MultiByteToWideChar(var_10[0x1], 0x9, esi, 0x1, arg_0, arg_0 != 0x0 ? 0x1 : 0x0);
                                            if (arg_0 == 0x0) {
                                                    eax = sub_47d812();
                                                    *eax = 0x2a;
                                                    if (var_4 != 0x0) {
                                                            eax = var_8;
                                                            eax[0x1c] = eax[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = eax | 0xffffffff;
                                            }
                                            else {
                                                    if (var_4 != 0x0) {
                                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x1;
                                            }
                                    }
                            }
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
