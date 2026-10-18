// sub_48f60c @ 0x48f60c
// hopper name: sub_48f60c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48f60c() {
    ecx = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if (ecx >= 0x0) {
            if (ecx > 0x2) {
                    if (ecx == 0x3) {
                            eax = *dword_bc64b4;
                    }
                    else {
                            *sub_47d812() = 0x16;
                            eax = sub_47a924();
                            eax = eax | 0xffffffff;
                    }
            }
            else {
                    eax = *dword_bc64b4;
                    *dword_bc64b4 = ecx;
            }
    }
    else {
            *sub_47d812() = 0x16;
            eax = sub_47a924();
            eax = eax | 0xffffffff;
    }
    return eax;
}
