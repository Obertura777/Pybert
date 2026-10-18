// sub_411030 @ 0x411030
// hopper name: sub_411030
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_411030() {
    decomp_var_c = *0x0;
    decomp_var_14 = esi;
    decomp_var_18 = edi;
    esp = esp - 0x1c;
    decomp_var_1c = *dword_4c8db8 ^ &decomp_var_18;
    *0x0 = &decomp_var_c;
    edi = ecx;
    eax = sub_47020b();
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            edx = *eax;
            esi = (edx[0x3])() + 0x10;
            decomp_var_10 = esi;
            if (*(int8_t *)byte_baed31 == 0x1) {
                    edx = &decomp_var_10;
                    sub_410c10(edx, "Albert-d%d", *dword_baed3c);
                    esi = decomp_var_10;
                    esp = (esp - 0xc) + 0xc;
                    if (*(esi - 0x4) > 0x1) {
                            esp = esp - 0x4;
                            sub_40b6e0(*(esi - 0xc), decomp_var_1c, decomp_var_18, decomp_var_14, decomp_var_10);
                            esi = decomp_var_10;
                    }
                    decomp_var_20 = "v6.0.1";
                    esp = esp - 0x8;
                    decomp_var_24 = esi;
            }
            else {
                    decomp_var_20 = "v6.0.1";
                    esp = esp - 0x8;
                    decomp_var_24 = 0x4afa30;
            }
            sub_45df20();
            eax = esi - 0x10;
            eax[0x3] = lock intrinsic_xadd(eax[0x3], edx | 0xffffffff);
            if (edx <= 0x1) {
                    esp = esp - 0x4;
                    decomp_var_28 = eax;
                    eax = *(**eax + 0x4);
                    eax = (eax)(decomp_var_28);
            }
            *0x0 = decomp_var_14;
    }
    return eax;
}
