// sub_47b03a @ 0x47b03a
// hopper name: sub_47b03a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b03a() {
    decomp_var_1c = ebx;
    esp = esp - 0x8;
    sub_47aea2(arg_8);
    if (var_14[0x2] == 0x0) {
            eax = sub_482db0(arg_0, arg_4);
            esp = (esp - 0x8) + 0x8;
            if (var_C != 0x0) {
                    var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
            }
    }
    else {
            eax = arg_4;
            if (eax == 0x0) {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    if (var_C != 0x0) {
                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                    }
                    eax = 0x0;
            }
            else {
                    ebx = 0x0;
                    if (*(int8_t *)eax == 0x0) {
                            if (var_C != ebx) {
                                    var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                            }
                            eax = arg_0;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_20 = esi;
                            esi = arg_0;
                            if (esi == ebx) {
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    if (var_C != ebx) {
                                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                            }
                            else {
                                    decomp_var_24 = edi;
                                    edi = esi;
                                    var_8 = esi - sub_47d630(eax);
                                    eax = sub_47d630(esi);
                                    eax = eax + var_8;
                                    esp = (esp - 0xc) + 0x8;
                                    if (*(int8_t *)esi != ebx) {
                                            esi = esi - arg_4;
                                            while (true) {
                                                    if (edi > eax) {
                                                            temp_1 = 0x1;
                                                            break;
                                                    }
                                                    edx = *(int8_t *)edi;
                                                    ecx = arg_4;
                                                    var_1 = edx;
                                                    if (edx != ebx) {
                                                            while (true) {
                                                                    edx = *(int8_t *)ecx;
                                                                    if (edx == ebx) {
                                                                            temp_0 = 0x2;
                                                                            break;
                                                                    }
                                                                    if (*(int8_t *)(esi + ecx) != edx) {
                                                                            temp_0 = 0x0;
                                                                            break;
                                                                    }
                                                                    ecx = ecx + 0x1;
                                                                    if (*(int8_t *)(esi + ecx) != ebx) {
                                                                            continue;
                                                                    }
                                                                    temp_0 = 0x1;
                                                                    break;
                                                            }
                                                            if (temp_0 != 0x0) {
                                                                    if (temp_0 != 0x1) {
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if (*(int8_t *)ecx != ebx) {
                                                                                    edi = edi + 0x1;
                                                                                    esi = esi + 0x1;
                                                                                    if ((*(int8_t *)((var_1 & 0xff) + var_14 + 0x1d) & 0x4) != 0x0) {
                                                                                            if (*(int8_t *)edi != ebx) {
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = esi + 0x1;
                                                                                                    if (*(int8_t *)edi != ebx) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    temp_1 = 0x2;
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    temp_1 = 0x0;
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (*(int8_t *)edi != ebx) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x2;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x3;
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (*(int8_t *)ecx != ebx) {
                                                                            edi = edi + 0x1;
                                                                            esi = esi + 0x1;
                                                                            if ((*(int8_t *)((var_1 & 0xff) + var_14 + 0x1d) & 0x4) != 0x0) {
                                                                                    if (*(int8_t *)edi != ebx) {
                                                                                            edi = edi + 0x1;
                                                                                            esi = esi + 0x1;
                                                                                            if (*(int8_t *)edi != ebx) {
                                                                                                    continue;
                                                                                            }
                                                                                            temp_1 = 0x2;
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            temp_1 = 0x0;
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (*(int8_t *)edi != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            temp_1 = 0x3;
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (*(int8_t *)ecx != ebx) {
                                                                    edi = edi + 0x1;
                                                                    esi = esi + 0x1;
                                                                    if ((*(int8_t *)((var_1 & 0xff) + var_14 + 0x1d) & 0x4) != 0x0) {
                                                                            if (*(int8_t *)edi != ebx) {
                                                                                    edi = edi + 0x1;
                                                                                    esi = esi + 0x1;
                                                                                    if (*(int8_t *)edi != ebx) {
                                                                                            continue;
                                                                                    }
                                                                                    temp_1 = 0x2;
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    temp_1 = 0x0;
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (*(int8_t *)edi != ebx) {
                                                                                    continue;
                                                                            }
                                                                            temp_1 = 0x2;
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    temp_1 = 0x3;
                                                                    break;
                                                            }
                                                    }
                                            }
                                            switch (temp_1) {
                                                case 0:
                                                    if (var_C != ebx) {
                                                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                                    break;
                                                case 1:
                                                    if (var_C != ebx) {
                                                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                                    break;
                                                case 2:
                                                    if (var_C != ebx) {
                                                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = 0x0;
                                                    break;
                                                default:
                                                    if (var_C != ebx) {
                                                            var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                                                    }
                                                    eax = edi;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (var_C != ebx) {
                                                    var_10[0x1c] = var_10[0x1c] & 0xfffffffd;
                                            }
                                            eax = 0x0;
                                    }
                                    esp = esp + 0x4;
                            }
                            esp = esp + 0x4;
                    }
            }
    }
    return eax;
}
