// sub_483d50 @ 0x483d50
// hopper name: sub_483d50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483d50() {
    &var_10 = &var_10 & 0xfffffff0;
    asm { fxch       st0, st1 };
    asm { fstp       qword [esp+0x10+var_10] };
    asm { fstp       qword [esp+0x10+var_8] };
    sub_483d69(var_10, var_10, var_8, var_8);
    return;
}
