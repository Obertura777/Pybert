// sub_48e150 @ 0x48e150
// hopper name: sub_48e150
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48e150() {
    eax = arg_0;
    if (eax == 0xfffffffe) {
            *sub_47d812() = 0x9;
            eax = 0x0;
    }
    else {
            esp = esp - 0x4;
            decomp_var_4 = esi;
            if (eax >= 0x0) {
                    if (eax >= *dword_bc7228) {
                            *sub_47d812() = 0x9;
                            sub_47a924();
                            eax = 0x0;
                    }
                    else {
                            eax = *(int8_t *)(*((SAR(eax, 0x5)) * 0x4 + dword_bc7240) + (eax & 0x1f) * 0x28 + 0x4) & 0xff;
                            eax = eax & 0x40;
                    }
            }
            else {
                    *sub_47d812() = 0x9;
                    sub_47a924();
                    eax = 0x0;
            }
    }
    return eax;
}
