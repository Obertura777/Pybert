// sub_40b4b0 @ 0x40b4b0
// hopper name: sub_40b4b0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40b4b0() {
    decomp_var_4 = ecx;
    decomp_var_8 = ebx;
    esp = esp - 0xc;
    decomp_var_c = esi;
    esi = ecx;
    var_1 = 0x0;
    ebx = 0x0;
    sub_4058d0(decomp_var_c);
    if (esi[0x24b3] != 0x0) {
            sub_407d00();
    }
    sub_4080f0();
    sub_4083d0(decomp_var_c, decomp_var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18);
    sub_408540(decomp_var_c, decomp_var_8, decomp_var_4, saved_fp);
    sub_408660();
    sub_408790(decomp_var_c, decomp_var_8, decomp_var_4, saved_fp);
    while (true) {
            eax = sub_40ace0();
            if (eax != 0x0) {
                    continue;
            }
            if (var_1 == eax) {
                    var_1 = 0x1;
                    if (sub_40afa0() != 0x0) {
                            continue;
                    }
                    if (ebx == 0x0) {
                            ebx = 0x1;
                            if (sub_40a030(decomp_var_c, decomp_var_8, decomp_var_4) != 0x0) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            break;
                    }
            }
            else {
                    if (ebx == 0x0) {
                            ebx = 0x1;
                            if (sub_40a030(decomp_var_c, decomp_var_8, decomp_var_4) != 0x0) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            break;
                    }
            }
    }
    sub_4089d0(decomp_var_c, decomp_var_8, decomp_var_4, saved_fp, arg_0, arg_4, arg_8, arg_c, arg_10, arg_14, arg_18, arg_1c, arg_20, arg_24, arg_28);
    sub_408ed0();
    sub_40a380();
    sub_40a720();
    sub_40a870();
    sub_40b470();
    return;
}
