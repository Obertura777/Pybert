// sub_48e43c @ 0x48e43c
// hopper name: sub_48e43c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e43c() {
    eax = arg_0;
    if (eax == 0xfffffffe) {
            eax = sub_47d825();
            *eax = *eax & 0x0;
            eax = sub_47d812();
            *eax = 0x9;
            eax = eax | 0xffffffff;
    }
    else {
            esp = esp - 0x4;
            decomp_var_4 = esi;
            if (eax >= 0x0) {
                    if (eax < *dword_bc7228) {
                            eax = (eax & 0x1f) * 0x28 + *((SAR(eax, 0x5)) * 0x4 + dword_bc7240);
                            if ((eax[0x4] & 0x1) == 0x0) {
                                    *sub_47d825() = 0x0;
                                    *sub_47d812() = 0x9;
                                    eax = sub_47a924();
                                    eax = eax | 0xffffffff;
                            }
                            else {
                                    eax = *eax;
                            }
                    }
                    else {
                            *sub_47d825() = 0x0;
                            *sub_47d812() = 0x9;
                            eax = sub_47a924();
                            eax = eax | 0xffffffff;
                    }
            }
            else {
                    *sub_47d825() = 0x0;
                    *sub_47d812() = 0x9;
                    eax = sub_47a924();
                    eax = eax | 0xffffffff;
            }
    }
    return eax;
}
