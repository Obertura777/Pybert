// sub_479294 @ 0x479294
// hopper name: sub_479294
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_479294() {
    eax = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    esi = *eax;
    if (esi != 0x0) {
            esp = esp - 0x4;
            decomp_var_8 = edi;
            if (esi == 0xffffffff) {
                    edx = ecx[0x2];
                    edi = 0x0;
                    if (edx > 0x0) {
                            eax = ecx[0x1];
                            while (true) {
                                    esi = *eax;
                                    if (esi == 0x0) {
                                            edi = edi + 0x1;
                                            eax = eax + 0x4;
                                            if (edi >= edx) {
                                                    sub_46dedc();
                                            }
                                            continue;
                                    }
                                    temp_2 = 0x1;
                                    break;
                            }
                            if (temp_2 != 0x0) {
                                    edi = *esi;
                                    if (edi == 0x0) {
                                            eax = esi[0x1];
                                            esp = esp - 0x4;
                                            decomp_var_c = ebx;
                                            ebx = ecx[0x2];
                                            edx = (eax >> 0x4) % ebx + 0x1;
                                            if (edx < ebx) {
                                                    eax = ecx[0x1];
                                                    eax = eax + edx * 0x4;
                                                    while (true) {
                                                            edi = *eax;
                                                            if (edi != 0x0) {
                                                                    temp_3 = 0x1;
                                                                    break;
                                                            }
                                                            edx = edx + 0x1;
                                                            eax = eax + 0x4;
                                                            if (edx < ebx) {
                                                                    continue;
                                                            }
                                                            temp_3 = 0x0;
                                                            break;
                                                    }
                                            }
                                            esp = esp + 0x4;
                                    }
                                    *arg_0 = edi;
                                    *arg_4 = esi[0x1];
                                    eax = esi[0x2];
                                    *arg_8 = eax;
                                    esp = esp + 0x4;
                            }
                    }
                    else {
                            edi = *esi;
                            if (edi == 0x0) {
                                    eax = esi[0x1];
                                    esp = esp - 0x4;
                                    decomp_var_c = ebx;
                                    ebx = ecx[0x2];
                                    edx = (eax >> 0x4) % ebx + 0x1;
                                    if (edx < ebx) {
                                            eax = ecx[0x1];
                                            eax = eax + edx * 0x4;
                                            while (true) {
                                                    edi = *eax;
                                                    if (edi != 0x0) {
                                                            temp_3 = 0x1;
                                                            break;
                                                    }
                                                    edx = edx + 0x1;
                                                    eax = eax + 0x4;
                                                    if (edx < ebx) {
                                                            continue;
                                                    }
                                                    temp_3 = 0x0;
                                                    break;
                                            }
                                    }
                                    esp = esp + 0x4;
                            }
                            *arg_0 = edi;
                            *arg_4 = esi[0x1];
                            eax = esi[0x2];
                            *arg_8 = eax;
                            esp = esp + 0x4;
                    }
            }
            else {
                    edi = *esi;
                    if (edi == 0x0) {
                            eax = esi[0x1];
                            esp = esp - 0x4;
                            decomp_var_c = ebx;
                            ebx = ecx[0x2];
                            edx = (eax >> 0x4) % ebx + 0x1;
                            if (edx < ebx) {
                                    eax = ecx[0x1];
                                    eax = eax + edx * 0x4;
                                    while (true) {
                                            edi = *eax;
                                            if (edi != 0x0) {
                                                    temp_3 = 0x1;
                                                    break;
                                            }
                                            edx = edx + 0x1;
                                            eax = eax + 0x4;
                                            if (edx < ebx) {
                                                    continue;
                                            }
                                            temp_3 = 0x0;
                                            break;
                                    }
                            }
                            esp = esp + 0x4;
                    }
                    *arg_0 = edi;
                    *arg_4 = esi[0x1];
                    eax = esi[0x2];
                    *arg_8 = eax;
                    esp = esp + 0x4;
            }
    }
    return eax;
}
