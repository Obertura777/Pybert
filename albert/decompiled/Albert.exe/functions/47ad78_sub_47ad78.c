// sub_47ad78 @ 0x47ad78
// hopper name: sub_47ad78
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47ad78() {
    decomp_var_8 = ebx;
    decomp_var_c = ebp;
    decomp_var_10 = esi;
    decomp_var_14 = edi;
    eax = sub_47fe7c(*dword_bc8378);
    decomp_var_1c = *dword_bc8374;
    esi = eax;
    var_4 = esi;
    edi = sub_47fe7c(*dword_bc8374);
    esp = (esp - 0x1c) + 0x8;
    if (edi >= esi) {
            ebx = edi - esi;
            ebp = ebx + 0x4;
            if (ebp >= 0x4) {
                    decomp_var_18 = esi;
                    esi = sub_47f73f();
                    esp = (esp - 0x4) + 0x4;
                    if (esi < ebp) {
                            eax = 0x800;
                            if (esi < 0x800) {
                                    eax = esi;
                            }
                            eax = eax + esi;
                            if (eax >= esi) {
                                    eax = sub_481308(var_4, eax);
                                    esp = (esp - 0x8) + 0x8;
                                    if (eax == 0x0) {
                                            eax = esi + 0x10;
                                            if (eax >= esi) {
                                                    eax = sub_481308(var_4, eax);
                                                    esp = (esp - 0x8) + 0x8;
                                                    if (eax != 0x0) {
                                                            edi = eax + (SAR(ebx, 0x2)) * 0x4;
                                                            esp = (esp - 0x4) + 0x4;
                                                            *dword_bc8378 = sub_47fe10(eax);
                                                            *edi = arg_0;
                                                            *dword_bc8374 = sub_47fe10(edi + 0x4);
                                                            esp = (esp - 0x4) + 0x4;
                                                            eax = arg_0;
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
                                            edi = eax + (SAR(ebx, 0x2)) * 0x4;
                                            esp = (esp - 0x4) + 0x4;
                                            *dword_bc8378 = sub_47fe10(eax);
                                            *edi = arg_0;
                                            *dword_bc8374 = sub_47fe10(edi + 0x4);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = arg_0;
                                    }
                            }
                            else {
                                    eax = esi + 0x10;
                                    if (eax >= esi) {
                                            eax = sub_481308(var_4, eax);
                                            esp = (esp - 0x8) + 0x8;
                                            if (eax != 0x0) {
                                                    edi = eax + (SAR(ebx, 0x2)) * 0x4;
                                                    esp = (esp - 0x4) + 0x4;
                                                    *dword_bc8378 = sub_47fe10(eax);
                                                    *edi = arg_0;
                                                    *dword_bc8374 = sub_47fe10(edi + 0x4);
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = arg_0;
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
                    else {
                            *edi = arg_0;
                            *dword_bc8374 = sub_47fe10(edi + 0x4);
                            esp = (esp - 0x4) + 0x4;
                            eax = arg_0;
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
