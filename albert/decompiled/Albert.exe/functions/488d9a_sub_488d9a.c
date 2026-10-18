// sub_488d9a @ 0x488d9a
// hopper name: sub_488d9a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_488d9a() {
    decomp_var_4 = ebx;
    decomp_var_8 = esi;
    esp = esp - 0xc;
    decomp_var_c = edi;
    if (*dword_bc837c == 0x0) {
            eax = sub_481a14();
    }
    esi = *dword_bc64ac;
    edi = 0x0;
    if (*dword_bc64ac == 0x0) {
            eax = eax | 0xffffffff;
    }
    else {
            while (true) {
                    eax = *(int8_t *)esi;
                    if (eax == 0x0) {
                            break;
                    }
                    if (eax != 0x3d) {
                            edi = edi + 0x1;
                    }
                    esp = (esp - 0x4) + 0x4;
                    esi = esi + sub_47d630(esi) + 0x1;
            }
            eax = sub_4812c0(edi + 0x1, 0x4);
            edi = eax;
            esp = (esp - 0x8) + 0x8;
            *dword_bc64dc = edi;
            if (edi != 0x0) {
                    esi = *dword_bc64ac;
                    esp = esp - 0x4;
                    decomp_var_10 = ebp;
                    while (true) {
                            if (*(int8_t *)esi != 0x0) {
                                    sub_47d630(esi);
                                    ebp = &arg_fffffffffffffffd;
                                    esp = (esp - 0x4) + 0x4;
                                    if (*(int8_t *)esi == 0x3d) {
                                            esi = esi + ebp;
                                            continue;
                                    }
                                    ebx = 0x0;
                                    eax = sub_4812c0(ebp, 0x1);
                                    esp = (esp - 0x8) + 0x8;
                                    *edi = eax;
                                    if (eax != 0x0) {
                                            esp = (esp - 0xc) + 0xc;
                                            if (sub_47db5e(eax, ebp, esi) != 0x0) {
                                                    decomp_var_14 = ebx;
                                                    decomp_var_18 = ebx;
                                                    sub_47a828();
                                                    esp = (esp - 0x14) + 0x14;
                                            }
                                            edi = edi + 0x4;
                                            esi = esi + ebp;
                                            continue;
                                    }
                                    esp = esp - 0x4;
                                    decomp_var_14 = *dword_bc64dc;
                                    eax = sub_47c8f9();
                                    *dword_bc64dc = 0x0;
                                    eax = eax | 0xffffffff;
                                    break;
                            }
                            esp = esp - 0x4;
                            decomp_var_14 = *dword_bc64ac;
                            sub_47c8f9();
                            *dword_bc64ac = 0x0;
                            *edi = 0x0;
                            *dword_bc8370 = 0x1;
                            eax = 0x0;
                            break;
                    }
                    esp = esp + 0x8;
            }
            else {
                    eax = eax | 0xffffffff;
            }
    }
    return eax;
}
