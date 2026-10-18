// sub_49226a @ 0x49226a
// hopper name: sub_49226a
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_49226a() {
    var_4 = ecx;
    asm { wait };
    asm { fnstsw     word [esp+0x4+var_4] };
    eax = sign_extend_32(var_4);
    return eax;
}
