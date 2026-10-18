// sub_465cf0 @ 0x465cf0
// hopper name: sub_465cf0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_465cf0() {
    edx = arg_0;
    eax = ecx[0x1];
    decomp_var_8 = ebx;
    decomp_var_c = esi;
    esi = edx[0x1];
    esp = esp - 0x10;
    decomp_var_10 = edi;
    ebx = 0x0;
    edi = 0x0;
    var_4 = esi;
    arg_0 = eax;
    if (eax >= esi) {
            arg_0 = esi;
    }
    edx = *edx;
    if (edx != 0x0) {
            esi = *ecx;
            if (esi != 0x0) {
                    esp = esp - 0x4;
                    var_14 = ebp;
                    ebp = edx - esi;
                    &var_14 = &var_14;
                    while (true) {
                            ecx = arg_0;
                            if (edi >= ecx) {
                                    if (ebx == 0x0) {
                                            temp_0 = 0x1;
                                    }
                                    else {
                                            temp_0 = 0x1;
                                    }
                                    break;
                            }
                            ecx = *(int16_t *)esi & 0xffff;
                            edx = *(int16_t *)(esi + ebp) & 0xffff;
                            bool_4 = edx >= ecx;
                            if (edx > ecx) {
                                    ebx = 0x1;
                            }
                            else {
                                    if (!bool_4) {
                                            ebx = 0x1;
                                    }
                            }
                            edi = edi + 0x1;
                            esi = esi + 0x2;
                            if (ebx == 0x0) {
                                    continue;
                            }
                            esp = esp + 0x14;
                            temp_0 = 0x0;
                            break;
                    }
            }
    }
    return;
}
