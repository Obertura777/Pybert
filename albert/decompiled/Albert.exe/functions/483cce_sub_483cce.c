// sub_483cce @ 0x483cce
// hopper name: sub_483cce
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_483cce() {
    asm { fld        qword [qword_value_4704009808640999424] };
    asm { fstp       qword [ebp+var_10] };
    asm { fld        qword [qword_value_4706263254500900864] };
    asm { fstp       qword [ebp+var_18] };
    asm { fld        qword [ebp+var_18] };
    asm { fdiv       qword [ebp+var_10] };
    asm { fmul       qword [ebp+var_10] };
    asm { fsubr      qword [ebp+var_18] };
    asm { fstp       qword [ebp+var_8] };
    asm { fld1 };
    asm { fcomp      qword [ebp+var_8] };
    asm { fnstsw     ax };
    if (!PARITY(HIBYTE(eax) & 0x5)) {
            eax = 0x1;
    }
    else {
            eax = 0x0;
    }
    return eax;
}
