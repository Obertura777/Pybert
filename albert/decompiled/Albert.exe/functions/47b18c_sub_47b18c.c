// sub_47b18c @ 0x47b18c
// hopper name: sub_47b18c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b18c() {
    decomp_var_14 = ebx;
    esp = esp - 0x8;
    sub_47aea2(arg_8);
    eax = arg_0;
    if (eax == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
            if (var_4 != 0x0) {
                    var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
            }
            eax = 0x0;
    }
    else {
            esp = esp - 0x4;
            decomp_var_18 = esi;
            esi = var_C;
            if (esi[0x2] == 0x0) {
                    eax = sub_482e50(eax, arg_4);
                    esp = (esp - 0x8) + 0x8;
                    if (var_4 != 0x0) {
                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                    }
                    esp = esp + 0x4;
            }
            else {
                    while (true) {
                            ecx = *(int8_t *)eax & 0xff;
                            ecx = ecx & 0xffff;
                            if (ecx == 0x0) {
                                    temp_0 = 0x0;
                                    break;
                            }
                            else {
                                    if ((*(int8_t *)((ecx & 0xff) + esi + 0x1d) & 0x4) != 0x0) {
                                            eax = eax + 0x1;
                                            edx = *(int8_t *)eax;
                                            if (edx != 0x0) {
                                                    ecx = (ecx & 0xffff) << 0x8 | edx & 0xff;
                                                    if (arg_4 != ecx) {
                                                            eax = eax + 0x1;
                                                            continue;
                                                    }
                                                    eax = eax - 0x1;
                                                    temp_0 = 0x1;
                                                    break;
                                            }
                                            else {
                                                    temp_0 = 0x2;
                                                    break;
                                            }
                                    }
                                    else {
                                            if (arg_4 != (ecx & 0xffff)) {
                                                    eax = eax + 0x1;
                                                    continue;
                                            }
                                            temp_0 = 0x0;
                                            break;
                                    }
                            }
                    }
                    if (temp_0 != 0x0) {
                            if (temp_0 != 0x1) {
                                    if (var_4 != 0x0) {
                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                            }
                            else {
                                    if (var_4 != 0x0) {
                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                    }
                            }
                            esp = esp + 0x4;
                    }
                    else {
                            if (arg_4 == (ecx & 0xffff)) {
                                    if (var_4 != 0x0) {
                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                    }
                            }
                            else {
                                    if (var_4 != 0x0) {
                                            var_8[0x1c] = var_8[0x1c] & 0xfffffffd;
                                    }
                                    eax = 0x0;
                            }
                            esp = esp + 0x4;
                    }
            }
    }
    return eax;
}
