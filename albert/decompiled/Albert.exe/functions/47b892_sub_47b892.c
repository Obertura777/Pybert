// sub_47b892 @ 0x47b892
// hopper name: sub_47b892
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b892() {
    if (arg_8 == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            esp = (esp - 0x14) + 0x14;
    }
    else {
            esp = esp - 0x4;
            decomp_var_8 = esi;
            esi = arg_0;
            if (esi != 0x0) {
                    ebx = 0x0;
                    if (arg_4 <= 0x0) {
                            *sub_47d812() = 0x16;
                            sub_47a924();
                            esp = (esp - 0x14) + 0x14;
                            esp = esp + 0x4;
                    }
                    else {
                            eax = sub_47b7c8(0x485bb7, esi, arg_4, arg_8, arg_c, arg_10);
                            esp = (esp - 0x18) + 0x18;
                            if (eax < ebx) {
                                    ebx = 0x0;
                                    *(int8_t *)esi = 0x0;
                            }
                            if (eax == 0xfffffffe) {
                                    *sub_47d812() = 0x22;
                                    sub_47a924();
                                    esp = (esp - 0x14) + 0x14;
                                    esp = esp + 0x4;
                            }
                            else {
                                    esp = esp + 0x4;
                            }
                    }
            }
            else {
                    *sub_47d812() = 0x16;
                    sub_47a924();
                    esp = (esp - 0x14) + 0x14;
                    esp = esp + 0x4;
            }
    }
    return;
}
