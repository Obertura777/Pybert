// sub_48de3c @ 0x48de3c
// hopper name: sub_48de3c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48de3c() {
    eax = arg_8;
    asm { fld        qword [ebp+arg_0] };
    ecx = arg_6;
    asm { fstp       qword [ebp+var_8] };
    eax = eax + 0x3fe << 0x4 | ecx & 0xffff800f;
    asm { fld        qword [ebp+var_8] };
    return eax;
}
