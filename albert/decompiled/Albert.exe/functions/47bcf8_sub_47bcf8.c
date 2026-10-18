// sub_47bcf8 @ 0x47bcf8
// hopper name: sub_47bcf8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47bcf8() {
    esp = esp - 0x8;
    sub_47f31c(0x4c33c0, 0xc);
    decomp_var_1c = 0x0;
    esi = arg_4;
    if (esi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            eax = sub_47f361();
    }
    else {
            if (arg_8 != 0x0) {
                    ebx = 0x0;
                    sub_4868de(esi);
                    esp = (esp - 0x4) + 0x4;
                    if ((esi[0xc] & 0x40) == 0x0) {
                            esp = (esp - 0x4) + 0x4;
                            if (sub_4867ae(esi) != 0xffffffff) {
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_4867ae(esi) != 0xfffffffe) {
                                            edi = (SAR(sub_4867ae(esi), 0x5)) * 0x4 + dword_bc7240;
                                            eax = sub_4867ae(esi);
                                            esp = (esp - 0x8) + 0x8;
                                            eax = (eax & 0x1f) * 0x28 + *edi;
                                    }
                                    else {
                                            eax = 0x4c9958;
                                    }
                            }
                            else {
                                    eax = 0x4c9958;
                            }
                            if ((eax[0x24] & 0x7f) == 0x0) {
                                    esp = (esp - 0x4) + 0x4;
                                    if (sub_4867ae(esi) != 0xffffffff) {
                                            esp = (esp - 0x4) + 0x4;
                                            if (sub_4867ae(esi) != 0xfffffffe) {
                                                    edi = (SAR(sub_4867ae(esi), 0x5)) * 0x4 + dword_bc7240;
                                                    eax = sub_4867ae(esi);
                                                    esp = (esp - 0x8) + 0x8;
                                                    eax = (eax & 0x1f) * 0x28 + *edi;
                                            }
                                            else {
                                                    eax = 0x4c9958;
                                            }
                                    }
                                    else {
                                            eax = 0x4c9958;
                                    }
                                    if ((eax[0x24] & 0x80) != 0x0) {
                                            ebx = 0x0;
                                            *sub_47d812() = 0x16;
                                            sub_47a924();
                                            esp = (esp - 0x14) + 0x14;
                                            decomp_var_1c = decomp_var_1c | 0xffffffff;
                                    }
                            }
                            else {
                                    *sub_47d812() = 0x16;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    decomp_var_1c = decomp_var_1c | 0xffffffff;
                            }
                    }
                    if (decomp_var_1c == ebx) {
                            edi = sub_486982(esi);
                            decomp_var_1c = sub_48517e();
                            sub_486a18(edi, esi);
                    }
                    sub_47be3d();
                    eax = sub_47f361();
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    eax = sub_47f361();
            }
    }
    return eax;
}
