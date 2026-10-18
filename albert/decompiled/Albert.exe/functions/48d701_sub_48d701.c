// sub_48d701 @ 0x48d701
// hopper name: sub_48d701
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48d701() {
    decomp_var_4 = eax;
    asm { fstp       tword [esp+0x30+var_24] };
    asm { fstp       tword [esp+0x30+var_30] };
    sub_48cf10(var_30, decomp_var_2c, decomp_var_28, var_24, decomp_var_20, decomp_var_1c, decomp_var_18, decomp_var_14);
    eax = decomp_var_4;
    return eax;
}
