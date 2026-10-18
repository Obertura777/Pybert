// sub_4784da @ 0x4784da
// hopper name: sub_4784da
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4784da() {
    esi = arg_c;
    edx = *esi;
    eax = ecx;
    esp = esp - 0xc;
    decomp_var_4 = eax;
    if (edx < 0x0) {
            sub_40b5a0(0x80070057);
    }
    else {
            ecx = arg_8;
            if (ecx != 0x0) {
                    if (*(int8_t *)ecx != 0x0) {
                            eax = *eax;
                            edi = *(eax - 0xc);
                            ebx = eax + edx;
                            edi = edi + eax;
                            if (ebx < edi) {
                                    decomp_var_20 = ebx;
                                    eax = sub_47f8a7(decomp_var_20, ecx);
                                    ebx = ebx + eax;
                                    esp = (esp - 0x8) + 0x8;
                                    arg_c = eax;
                                    if (ebx < edi) {
                                            eax = sub_47f97f(ebx, arg_8);
                                            ecx = *esi;
                                            decomp_var_1c = eax;
                                            decomp_var_20 = ecx + arg_c;
                                            esp = (esp - 0x8) + 0x8 - 0xc;
                                            decomp_var_24 = arg_4;
                                            *esi = ecx + arg_c + eax + 0x1;
                                            sub_40c2e0();
                                    }
                                    else {
                                            eax = decomp_var_4;
                                            *esi = *esi | 0xffffffff;
                                            esp = esp - 0x4;
                                            decomp_var_1c = sub_40c010();
                                            sub_40b7d0();
                                    }
                            }
                            else {
                                    eax = decomp_var_4;
                                    *esi = *esi | 0xffffffff;
                                    esp = esp - 0x4;
                                    decomp_var_1c = sub_40c010();
                                    sub_40b7d0();
                            }
                    }
                    else {
                            edi = *eax;
                            if (edx < *(edi - 0xc)) {
                                    decomp_var_1c = sub_40c010();
                                    esp = esp - 0x8;
                                    decomp_var_20 = *esi + edi;
                                    sub_47849b();
                            }
                            else {
                                    *esi = *esi | 0xffffffff;
                                    esp = esp - 0x4;
                                    decomp_var_1c = sub_40c010();
                                    sub_40b7d0();
                            }
                    }
            }
            else {
                    edi = *eax;
                    if (edx < *(edi - 0xc)) {
                            decomp_var_1c = sub_40c010();
                            esp = esp - 0x8;
                            decomp_var_20 = *esi + edi;
                            sub_47849b();
                    }
                    else {
                            *esi = *esi | 0xffffffff;
                            esp = esp - 0x4;
                            decomp_var_1c = sub_40c010();
                            sub_40b7d0();
                    }
            }
    }
    return;
}
