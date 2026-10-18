// PrepareDrawVoteSet @ 0x44c9d0
// hopper name: sub_44c9d0
// pybert name: PrepareDrawVoteSet
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

PrepareDrawVoteSet() {
    decomp_var_c = *0x0;
    decomp_var_48 = esi;
    decomp_var_4c = edi;
    esp = esp - 0x50;
    decomp_var_50 = *dword_4c8db8 ^ &decomp_var_4c;
    *0x0 = &decomp_var_c;
    edi = ecx;
    eax = sub_401e30();
    eax[0x11] = 0x1;
    eax[0x1] = eax;
    *eax = eax;
    eax[0x2] = eax;
    eax = sub_47020b();
    if (eax == 0x0) {
            esp = esp - 0x4;
            decomp_var_54 = 0x80004005;
            eax = sub_40b5a0(0x80004005);
    }
    (*(*eax + 0xc))() + 0x10;
    edx = decomp_var_30[0x1];
    esp = esp - 0x4;
    sub_401950(edx);
    decomp_var_30[0x1] = decomp_var_30;
    *decomp_var_30 = decomp_var_30;
    decomp_var_30[0x2] = decomp_var_30;
    decomp_var_40 = 0x0;
    if (*(edi[0x2] + 0x2404) > 0x0) {
            sub_44caa0(decomp_var_54, decomp_var_50, decomp_var_4c, decomp_var_48, decomp_var_44, decomp_var_40, decomp_var_3c, decomp_var_38, decomp_var_34, decomp_var_30, decomp_var_2c, decomp_var_28, decomp_var_24, decomp_var_20);
    }
    esp = esp - 0x4;
    decomp_var_58 = &decomp_var_34;
    *(int8_t *)byte_baed2b = sub_4440e0(decomp_var_58);
    eax = decomp_var_40 - 0x10;
    eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
    if (edx <= 0x1) {
            esp = esp - 0x4;
            (*(**eax + 0x4))(eax);
    }
    sub_403430(&decomp_var_40, &decomp_var_38, *decomp_var_34, &decomp_var_38, decomp_var_34);
    sub_47c8f9();
    *0x0 = decomp_var_14;
    return;
}
