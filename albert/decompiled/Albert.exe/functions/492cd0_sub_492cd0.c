// sub_492cd0 @ 0x492cd0
// hopper name: sub_492cd0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492cd0() {
    eax = arg_0;
    esp = esp - 0x4;
    decomp_var_4 = esi;
    if (eax == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            eax = 0x16;
    }
    else {
            *eax = *dword_bc6f74;
            eax = 0x0;
    }
    return eax;
}
