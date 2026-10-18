// sub_4741ee @ 0x4741ee
// hopper name: sub_4741ee
// referenced by: immediate
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4741ee() {
    if (arg_4 != 0x360) {
            esi = arg_0;
            esp = esp - 0x8;
            eax = sub_473b15();
            if (eax != 0x0) {
                    if (eax[0x8] == esi) {
                            decomp_var_8 = arg_c;
                            esp = esp - 0x14;
                            sub_474101();
                            esp = esp + 0x4;
                    }
                    else {
                            decomp_var_8 = arg_c;
                            esp = esp - 0x10;
                            DefWindowProcA(esi, arg_4, arg_8, decomp_var_8);
                            esp = esp + 0x4;
                    }
            }
            else {
                    decomp_var_8 = arg_c;
                    esp = esp - 0x10;
                    DefWindowProcA(esi, arg_4, arg_8, decomp_var_8);
                    esp = esp + 0x4;
            }
    }
    return;
}
