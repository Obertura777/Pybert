// sub_484ca7 @ 0x484ca7
// hopper name: sub_484ca7
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_484ca7() {
    var_20 = eax;
    asm { fstp       qword [ebp+var_8] };
    eax = sub_48dc9b(edx, &var_20, &arg_0);
    asm { fld        qword [ebp+var_8] };
    if (arg_0 != 0x27f) {
            asm { fldcw      word [ebp+arg_0] };
    }
    return eax;
}
