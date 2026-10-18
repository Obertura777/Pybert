// sub_4704c5 @ 0x4704c5
// hopper name: sub_4704c5
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4704c5() {
    ebx = arg_0;
    decomp_var_8 = esi;
    decomp_var_c = edi;
    edi = arg_4;
    esi = ecx;
    esp = esp - 0x18;
    if (sub_46ee21() != 0x0) {
            eax = 0x1;
    }
    else {
            if (edi != 0x0) {
                    if (edi == 0xffffffff) {
                            if (ebx < 0x0) {
                                    if (ebx < 0xf000) {
                                            eax = GetParent(esi[0x8]);
                                            esp = esp - 0x8;
                                            eax = sub_473aee(eax);
                                            if (eax != 0x0) {
                                                    esp = esp - 0x10;
                                                    if ((*(*eax + 0xc))(ebx, edi, arg_8, arg_c) == 0x0) {
                                                            eax = sub_46f313();
                                                            if (eax != 0x0) {
                                                                    esp = esp - 0x10;
                                                                    if ((*(*eax + 0xc))(ebx, edi, arg_8, arg_c) == 0x0) {
                                                                            eax = 0x0;
                                                                    }
                                                                    else {
                                                                            eax = 0x1;
                                                                    }
                                                            }
                                                            else {
                                                                    eax = 0x0;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                    }
                                            }
                                            else {
                                                    eax = sub_46f313();
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x10;
                                                            if ((*(*eax + 0xc))(ebx, edi, arg_8, arg_c) == 0x0) {
                                                                    eax = 0x0;
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
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
                    }
                    else {
                            eax = 0x0;
                    }
            }
            else {
                    if (ebx < 0x0) {
                            if (ebx < 0xf000) {
                                    eax = GetParent(esi[0x8]);
                                    esp = esp - 0x8;
                                    eax = sub_473aee(eax);
                                    if (eax != 0x0) {
                                            esp = esp - 0x10;
                                            if ((*(*eax + 0xc))(ebx, edi, arg_8, arg_c) == 0x0) {
                                                    eax = sub_46f313();
                                                    if (eax != 0x0) {
                                                            esp = esp - 0x10;
                                                            if ((*(*eax + 0xc))(ebx, edi, arg_8, arg_c) == 0x0) {
                                                                    eax = 0x0;
                                                            }
                                                            else {
                                                                    eax = 0x1;
                                                            }
                                                    }
                                                    else {
                                                            eax = 0x0;
                                                    }
                                            }
                                            else {
                                                    eax = 0x1;
                                            }
                                    }
                                    else {
                                            eax = sub_46f313();
                                            if (eax != 0x0) {
                                                    esp = esp - 0x10;
                                                    if ((*(*eax + 0xc))(ebx, edi, arg_8, arg_c) == 0x0) {
                                                            eax = 0x0;
                                                    }
                                                    else {
                                                            eax = 0x1;
                                                    }
                                            }
                                            else {
                                                    eax = 0x0;
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
            }
    }
    return eax;
}
