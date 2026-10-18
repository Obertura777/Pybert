// sub_48dd97 @ 0x48dd97
// hopper name: sub_48dd97
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48dd97() {
    var_8 = ecx;
    asm { fld        qword [esp+0x8+arg_0] };
    asm { frndint };
    asm { fstp       qword [esp+0x8+var_8] };
    asm { fld        qword [esp+0x8+var_8] };
    return;
}
