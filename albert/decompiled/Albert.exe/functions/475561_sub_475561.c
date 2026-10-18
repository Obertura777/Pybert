// sub_475561 @ 0x475561
// hopper name: sub_475561
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_475561() {
    decomp_var_38 = esi;
    esp = esp - 0x8;
    decomp_var_3c = edi;
    edi = arg_c;
    esi = ecx;
    if (edi != 0x0) {
            esp = esp - 0x8;
            if (sub_47858d(edi) == 0x0) {
                    sub_46dedc();
            }
            decomp_var_4 = arg_4;
            decomp_var_8 = arg_8;
            decomp_var_10 = arg_10;
            decomp_var_14 = arg_14;
            decomp_var_18 = arg_18;
            decomp_var_1c = arg_1c;
            decomp_var_20 = arg_20;
            decomp_var_24 = arg_24;
            decomp_var_c = edi;
            decomp_var_28 = arg_28;
            decomp_var_2c = *(sub_4715ba() + 0x8);
            decomp_var_30 = arg_2c;
            eax = *esi;
            esp = esp - 0x4;
            eax = (eax[0x19])(&decomp_var_30);
            if (eax == 0x0) {
                    (*(*esi + 0x114))();
            }
            else {
                    sub_47550c();
                    esp = (esp - 0x34) + 0x30;
                    edi = sub_47263c();
                    if (sub_473b96() == 0x0) {
                            (*(*esi + 0x114))();
                    }
            }
    }
    else {
            decomp_var_4 = arg_4;
            decomp_var_8 = arg_8;
            decomp_var_10 = arg_10;
            decomp_var_14 = arg_14;
            decomp_var_18 = arg_18;
            decomp_var_1c = arg_1c;
            decomp_var_20 = arg_20;
            decomp_var_24 = arg_24;
            decomp_var_c = edi;
            decomp_var_28 = arg_28;
            decomp_var_2c = *(sub_4715ba() + 0x8);
            decomp_var_30 = arg_2c;
            eax = *esi;
            esp = esp - 0x4;
            eax = (eax[0x19])(&decomp_var_30);
            if (eax == 0x0) {
                    (*(*esi + 0x114))();
            }
            else {
                    sub_47550c();
                    esp = (esp - 0x34) + 0x30;
                    edi = sub_47263c();
                    if (sub_473b96() == 0x0) {
                            (*(*esi + 0x114))();
                    }
            }
    }
    return;
}
