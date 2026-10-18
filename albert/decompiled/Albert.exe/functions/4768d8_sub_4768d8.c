// sub_4768d8 @ 0x4768d8
// hopper name: sub_4768d8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4768d8() {
    edi = arg_c;
    if (edi[0x8] == 0x0 && sub_476696() == 0x0) {
            decomp_var_c = ebx;
            ebx = arg_8;
            decomp_var_10 = esi;
            esi = arg_4;
            sub_476899(ebx, decomp_var_10, decomp_var_c);
            esp = esp - 0x14;
            eax = sub_4766ef(ebx, &arg_c);
            if (arg_c != 0x0) {
                    esp = esp - 0x4;
                    if (sub_474550(arg_c) == 0x0) {
                            sub_46dec2();
                    }
                    if (arg_c == 0x0) {
                            esp = esp - 0x4;
                            if (sub_4766b8() != 0x0) {
                                    esp = esp - 0x8;
                                    sub_4767f7(decomp_var_10, decomp_var_c);
                            }
                            esp = esp + 0x8;
                    }
                    else {
                            esp = esp - 0x4;
                            decomp_var_18 = edi[0x8];
                            esi = esi[0x1];
                            if (esi[0x8] != GetParent(decomp_var_18)) {
                                    esp = esp - 0x8;
                                    sub_4767f7(decomp_var_10, decomp_var_c);
                            }
                            esp = esp + 0x8;
                    }
            }
            else {
                    esp = esp - 0x4;
                    if (sub_4766b8() != 0x0) {
                            esp = esp - 0x8;
                            sub_4767f7(decomp_var_10, decomp_var_c);
                    }
                    esp = esp + 0x8;
            }
    }
    return;
}
