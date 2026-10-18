// sub_482823 @ 0x482823
// hopper name: sub_482823
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_482823() {
    esp = esp - 0x8;
    sub_47f31c(0x4c37d8, 0x14);
    decomp_var_20 = 0x0;
    if (arg_4 > 0x5) {
            *sub_47d812() = 0x16;
            sub_47a924();
    }
    else {
            esi = sub_480086();
            sub_481ce6();
            esi[0x1c] = esi[0x1c] | 0x10;
            esp = (esp - 0x8) + 0x8;
            edi = sub_4812c0(0xd8, 0x1);
            if (edi != 0x0) {
                    ebx = 0x0;
                    sub_487c06(0xc);
                    sub_481c84();
                    sub_482951();
                    decomp_var_c = arg_4;
                    eax = sub_482655();
                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                    decomp_var_20 = eax;
                    if (eax != 0x0) {
                            if (arg_8 != ebx) {
                                    esp = (esp - 0x8) + 0x8;
                                    if (sub_47fd80(arg_8, 0x4c9518) != 0x0) {
                                            *dword_bc686c = 0x1;
                                    }
                            }
                            sub_487c06(0xc);
                            decomp_var_4 = 0x2;
                            ebx = esi + 0x6c;
                            sub_481ca8();
                            sub_481bf8(edi);
                            esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                            if ((esi[0x70] & 0x2) == 0x0 && (*(int8_t *)byte_4c9514 & 0x1) == 0x0) {
                                    sub_481ca8();
                                    sub_47c000(0xbc6870, *dword_4c95f8 + 0xc, 0x18);
                                    sub_481d5c();
                            }
                            sub_48295d();
                    }
                    else {
                            sub_481bf8(edi);
                            sub_481a32(edi);
                    }
            }
            sub_48298e();
    }
    eax = sub_47f361();
    return eax;
}
