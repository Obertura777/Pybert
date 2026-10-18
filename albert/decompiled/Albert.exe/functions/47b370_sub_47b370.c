// sub_47b370 @ 0x47b370
// hopper name: sub_47b370
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b370() {
    if (*dword_bc8364 != 0x0) {
            esp = esp - 0x8;
            asm { stmxcsr    dword [esp+0x8+var_4] };
            bool_1 = (var_4 & 0x1f80) != 0x1f80;
            if ((var_4 & 0x1f80) == 0x1f80) {
                    asm { fnstcw     word [esp+0x8+var_8] };
            }
            esp = esp + 0x8;
            if (!bool_1) {
                    eax = sub_483d50();
            }
            else {
                    asm { fxch       st0, st1 };
                    asm { fstp       qword [esp+0x1c+var_1C] };
                    asm { fst        qword [esp+0x1c+var_14] };
                    eax = sub_47b3cd(var_1C, var_1C, var_14, var_10);
            }
    }
    else {
            asm { fxch       st0, st1 };
            asm { fstp       qword [esp+0x1c+var_1C] };
            asm { fst        qword [esp+0x1c+var_14] };
            eax = sub_47b3cd(var_1C, var_1C, var_14, var_10);
    }
    return eax;
}
