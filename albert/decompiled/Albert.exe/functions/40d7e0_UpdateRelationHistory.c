// UpdateRelationHistory @ 0x40d7e0
// hopper name: sub_40d7e0
// pybert name: UpdateRelationHistory
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

UpdateRelationHistory() {
    esp = esp - 0x14;
    eax = ecx[0x2];
    eax = eax[0x901];
    decomp_var_14 = 0x0;
    if (eax <= 0x0) goto .l1;
    goto loc_40d7ff;

.l1:
    return;

loc_40d7ff:
    decomp_var_18 = ebx;
    decomp_var_1c = ebp;
    decomp_var_20 = esi;
    esp = esp - 0x10;
    decomp_var_24 = edi;
    decomp_var_c = 0x634e90;
    decomp_var_10 = 0x4d5528;
    goto loc_40d815;

loc_40d815:
    if (eax > 0x0) {
            sub_40d820(decomp_var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10, decomp_var_c, decomp_var_8);
    }
    eax = ecx[0x2];
    eax = eax[0x901];
    bool_2 = decomp_var_14 + 0x1 < eax;
    decomp_var_14 = decomp_var_14 + 0x1;
    decomp_var_10 = decomp_var_10 + 0xa8;
    decomp_var_c = decomp_var_c + 0x54;
    if (bool_2) {
            continue;
    }
    esp = esp + 0x10;
    temp_0 = 0x1;
    break;
    return;
}
