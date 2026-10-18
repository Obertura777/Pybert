// sub_484e7c @ 0x484e7c
// hopper name: sub_484e7c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_484e7c() {
    asm { fld        qword [ebp+arg_0] };
    var_10 = ecx;
    esp = esp - 0x8;
    var_10 = ecx;
    asm { fstp       qword [esp+0x10+var_10] };
    eax = sub_48dda8(var_10, var_10);
    ecx = var_10;
    esp = esp + 0x8;
    if ((eax & 0x90) == 0x0) {
            asm { fld        qword [ebp+arg_0] };
            var_10 = ecx;
            esp = esp - 0x8;
            var_10 = ecx;
            asm { fstp       qword [esp+0x10+var_10] };
            eax = sub_48dd97(var_10);
            asm { fcomp      qword [ebp+arg_0] };
            ecx = var_10;
            esp = esp + 0x8;
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x44)) {
                    asm { fld        qword [ebp+arg_0] };
                    esp = esp - 0x4;
                    asm { fmul       qword [qword_value_4602678819172646912] };
                    esp = esp - 0x4;
                    var_10 = ecx;
                    asm { fstp       qword [ebp+var_8] };
                    asm { fld        qword [ebp+var_8] };
                    asm { fstp       qword [esp+0x10+var_10] };
                    eax = sub_48dd97(var_10);
                    asm { fcomp      qword [ebp+var_8] };
                    esp = esp + 0x8;
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x44)) {
                            eax = 0x2;
                    }
                    else {
                            eax = 0x1;
                    }
            }
            else {
                    eax = 0x0;
            }
    }
    else {
            eax = 0x0;
    }
    return eax;
}
