// UpdateScoreState @ 0x44c8e0
// hopper name: sub_44c8e0
// pybert name: UpdateScoreState
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

UpdateScoreState() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    esp = esp - 0x20;
    decomp_var_20 = edi;
    ebp = ecx;
    edi = 0x0;
    var_C = 0x0;
    if (arg_0[0x901] > 0x0) {
            if (*(edi * 0x4 + 0x62e460) > 0x0) {
                    esp = esp - 0x8;
                    eax = sub_401ff0(&var_8, &var_C, decomp_var_20, decomp_var_1c, decomp_var_18);
                    esi = eax;
                    eax = *esi;
                    if (eax == 0x0 || eax != 0xbc1e00) {
                            sub_47a948();
                    }
                    if (esi[0x1] != *dword_bc1e04) {
                            esp = esp - 0x4;
                            sub_442770(edi);
                    }
            }
            edi = edi + 0x1;
            var_C = edi;
            if (edi < arg_0[0x901]) {
                    continue;
            }
            break;
    }
    edi = 0x0;
    var_C = 0x0;
    if (arg_0[0x901] > 0x0) {
            if (*(edi * 0x4 + 0x62e460) > 0x0) {
                    esp = esp - 0x8;
                    eax = sub_401ff0(&var_8, &var_C, decomp_var_20, decomp_var_1c, decomp_var_18);
                    esi = eax;
                    eax = *esi;
                    if (eax == 0x0 || eax != 0xbc1e00) {
                            sub_47a948();
                    }
                    if (esi[0x1] != *dword_bc1e04) {
                            esp = esp - 0x4;
                            sub_424490(edi, decomp_var_20);
                    }
            }
            edi = edi + 0x1;
            var_C = edi;
            if (edi < arg_0[0x901]) {
                    continue;
            }
            break;
    }
    &decomp_var_10 = decomp_var_18;
    return;
}
