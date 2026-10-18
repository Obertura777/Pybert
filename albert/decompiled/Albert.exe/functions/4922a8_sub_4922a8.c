// sub_4922a8 @ 0x4922a8
// hopper name: sub_4922a8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4922a8() {
    var_8 = ecx;
    esp = esp - 0x8;
    var_8 = ecx;
    ecx = arg_0;
    if ((ecx & 0x1) != 0x0) {
            asm { fld        tword [dword_4c9fac+236] };
            asm { fistp      dword [esp+0x8+arg_0] };
            asm { wait };
    }
    if ((ecx & 0x8) != 0x0) {
            asm { wait };
            asm { fnstsw     ax };
            asm { fld        tword [dword_4c9fac+236] };
            asm { fstp       qword [esp+0x8+var_8] };
            asm { wait };
            asm { wait };
            asm { fnstsw     ax };
    }
    if ((ecx & 0x10) != 0x0) {
            asm { fld        tword [dword_4c9fac+248] };
            asm { fstp       qword [esp+0x8+var_8] };
            asm { wait };
    }
    if ((ecx & 0x4) != 0x0) {
            asm { fldz };
            asm { fld1 };
            asm { fdivrp     st1 };
            asm { fstp       st0 };
            asm { wait };
    }
    if ((ecx & 0x20) != 0x0) {
            asm { fldpi };
            asm { fstp       qword [esp+0x8+var_8] };
            asm { wait };
    }
    return;
}
