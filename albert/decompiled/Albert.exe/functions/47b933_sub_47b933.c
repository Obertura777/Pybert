// sub_47b933 @ 0x47b933
// hopper name: sub_47b933
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b933() {
    if (arg_c == 0x0) {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            esp = (esp - 0x14) + 0x14;
            eax = eax | 0xffffffff;
    }
    else {
            decomp_var_c = esi;
            esi = arg_0;
            esp = esp - 0x8;
            decomp_var_10 = edi;
            if (arg_8 == 0x0) {
                    ebx = 0x0;
                    if (esi == 0x0) {
                            if (arg_4 == ebx) {
                                    eax = 0x0;
                                    esp = esp + 0x8;
                            }
                            else {
                                    *sub_47d812() = 0x16;
                                    eax = sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = eax | 0xffffffff;
                                    esp = esp + 0x8;
                            }
                    }
                    else {
                            edi = arg_4;
                            if (edi <= ebx) {
                                    *sub_47d812() = 0x16;
                                    eax = sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = eax | 0xffffffff;
                                    esp = esp + 0x8;
                            }
                            else {
                                    eax = sub_47d812();
                                    decomp_var_14 = arg_14;
                                    decomp_var_18 = arg_10;
                                    esp = esp - 0xc;
                                    decomp_var_1c = arg_c;
                                    if (edi > arg_8) {
                                            edi = *eax;
                                            eax = sub_47b7c8(0x485bb7, esi, arg_8 + 0x1, decomp_var_1c, decomp_var_18, decomp_var_14);
                                            esp = (esp - 0xc) + 0x18;
                                            if (eax == 0xfffffffe) {
                                                    eax = sub_47d812();
                                                    if (*eax == 0x22) {
                                                            eax = sub_47d812();
                                                            *eax = edi;
                                                    }
                                                    eax = eax | 0xffffffff;
                                                    esp = esp + 0x8;
                                            }
                                            else {
                                                    ebx = 0x0;
                                                    if (eax < 0x0) {
                                                            *(int8_t *)esi = ebx;
                                                            if (eax == 0xfffffffe) {
                                                                    *sub_47d812() = 0x22;
                                                                    eax = sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                            else {
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp + 0x8;
                                                    }
                                            }
                                    }
                                    else {
                                            var_4 = *eax;
                                            eax = sub_47b7c8(0x485bb7, esi, edi, decomp_var_1c, decomp_var_18, decomp_var_14);
                                            esp = (esp - 0xc) + 0x18;
                                            *(int8_t *)(esi + (edi - 0x1)) = ebx;
                                            if (eax == 0xfffffffe) {
                                                    if (arg_8 == 0xffffffff) {
                                                            eax = sub_47d812();
                                                            if (*eax == 0x22) {
                                                                    eax = sub_47d812();
                                                                    *eax = var_4;
                                                            }
                                                            eax = eax | 0xffffffff;
                                                            esp = esp + 0x8;
                                                    }
                                                    else {
                                                            *(int8_t *)esi = ebx;
                                                            if (eax == 0xfffffffe) {
                                                                    *sub_47d812() = 0x22;
                                                                    eax = sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            eax = eax | 0xffffffff;
                                                            esp = esp + 0x8;
                                                    }
                                            }
                                            else {
                                                    ebx = 0x0;
                                                    if (eax < 0x0) {
                                                            *(int8_t *)esi = ebx;
                                                            if (eax == 0xfffffffe) {
                                                                    *sub_47d812() = 0x22;
                                                                    eax = sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                            else {
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp + 0x8;
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    ebx = 0x0;
                    if (esi != 0x0) {
                            ebx = 0x0;
                            edi = arg_4;
                            if (edi <= 0x0) {
                                    *sub_47d812() = 0x16;
                                    eax = sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    eax = eax | 0xffffffff;
                                    esp = esp + 0x8;
                            }
                            else {
                                    eax = sub_47d812();
                                    decomp_var_14 = arg_14;
                                    decomp_var_18 = arg_10;
                                    esp = esp - 0xc;
                                    decomp_var_1c = arg_c;
                                    if (edi > arg_8) {
                                            edi = *eax;
                                            eax = sub_47b7c8(0x485bb7, esi, arg_8 + 0x1, decomp_var_1c, decomp_var_18, decomp_var_14);
                                            esp = (esp - 0xc) + 0x18;
                                            if (eax == 0xfffffffe) {
                                                    eax = sub_47d812();
                                                    if (*eax == 0x22) {
                                                            eax = sub_47d812();
                                                            *eax = edi;
                                                    }
                                                    eax = eax | 0xffffffff;
                                                    esp = esp + 0x8;
                                            }
                                            else {
                                                    if (eax < ebx) {
                                                            *(int8_t *)esi = ebx;
                                                            if (eax == 0xfffffffe) {
                                                                    *sub_47d812() = 0x22;
                                                                    eax = sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                            else {
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp + 0x8;
                                                    }
                                            }
                                    }
                                    else {
                                            var_4 = *eax;
                                            eax = sub_47b7c8(0x485bb7, esi, edi, decomp_var_1c, decomp_var_18, decomp_var_14);
                                            esp = (esp - 0xc) + 0x18;
                                            *(int8_t *)(esi + (edi - 0x1)) = ebx;
                                            if (eax == 0xfffffffe) {
                                                    if (arg_8 == 0xffffffff) {
                                                            eax = sub_47d812();
                                                            if (*eax == 0x22) {
                                                                    eax = sub_47d812();
                                                                    *eax = var_4;
                                                            }
                                                            eax = eax | 0xffffffff;
                                                            esp = esp + 0x8;
                                                    }
                                                    else {
                                                            *(int8_t *)esi = ebx;
                                                            if (eax == 0xfffffffe) {
                                                                    *sub_47d812() = 0x22;
                                                                    eax = sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                            }
                                                            eax = eax | 0xffffffff;
                                                            esp = esp + 0x8;
                                                    }
                                            }
                                            else {
                                                    if (eax < ebx) {
                                                            *(int8_t *)esi = ebx;
                                                            if (eax == 0xfffffffe) {
                                                                    *sub_47d812() = 0x22;
                                                                    eax = sub_47a924();
                                                                    esp = (esp - 0x14) + 0x14;
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                            else {
                                                                    eax = eax | 0xffffffff;
                                                                    esp = esp + 0x8;
                                                            }
                                                    }
                                                    else {
                                                            esp = esp + 0x8;
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            *sub_47d812() = 0x16;
                            eax = sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            eax = eax | 0xffffffff;
                            esp = esp + 0x8;
                    }
            }
    }
    return eax;
}
