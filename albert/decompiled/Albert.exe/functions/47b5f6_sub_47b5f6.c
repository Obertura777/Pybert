// sub_47b5f6 @ 0x47b5f6
// hopper name: sub_47b5f6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b5f6() {
    &var_20 = &var_20 & 0xfffffff0;
    asm { fld        st0 };
    asm { fst        dword [esp+0x20+var_8] };
    asm { fistp      qword [esp+0x20+var_10] };
    asm { fild       qword [esp+0x20+var_10] };
    edx = var_8;
    eax = var_10;
    if (eax != 0x0) {
            asm { fsubp      st1 };
            if (edx < 0x0) {
                    asm { fstp       dword [esp+0x20+var_20] };
                    eax = eax + 0x0 + CARRY(EFLAGS(cf));
            }
            else {
                    asm { fstp       dword [esp+0x20+var_20] };
                    eax = eax - 0x0 + CARRY(EFLAGS(cf));
            }
    }
    else {
            edx = var_C;
            if ((edx & 0x7fffffff) == 0x0) {
                    asm { fstp       dword [esp+0x20+var_8] };
                    asm { fstp       dword [esp+0x20+var_8] };
            }
            else {
                    asm { fsubp      st1 };
                    if (edx < 0x0) {
                            asm { fstp       dword [esp+0x20+var_20] };
                            eax = eax + 0x0 + CARRY(EFLAGS(cf));
                    }
                    else {
                            asm { fstp       dword [esp+0x20+var_20] };
                            eax = eax - 0x0 + CARRY(EFLAGS(cf));
                    }
            }
    }
    return eax;
}
