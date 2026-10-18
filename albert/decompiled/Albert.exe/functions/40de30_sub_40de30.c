// sub_40de30 @ 0x40de30
// hopper name: sub_40de30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40de30() {
    var_8 = 0x494948;
    var_C = *0x0;
    decomp_var_30 = ebx;
    decomp_var_34 = esi;
    *0x0 = &var_C;
    esi = ecx;
    sub_465870();
    esp = esp - 0x3c;
    decomp_var_3c = word_4c6cdc;
    if (arg_0 == 0x1) {
            sub_465f30(decomp_var_3c);
            sub_465ff0(&var_1C);
            sub_465fa0();
            esp = esp - 0x8;
            eax = sub_45a9b0(&var_2C);
            *(int8_t *)byte_baed5d = 0x1;
    }
    else {
            eax = sub_466ed0(&var_1C, decomp_var_3c);
            sub_465ff0(eax);
            sub_465fa0();
            esp = esp - 0xc;
            eax = sub_45a9b0(&var_2C);
            *(int8_t *)byte_baed5d = 0x0;
    }
    eax = sub_465fa0();
    *0x0 = var_8;
    return eax;
}
