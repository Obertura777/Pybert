// sub_48d91c @ 0x48d91c
// hopper name: sub_48d91c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48d91c() {
    decomp_var_4 = edx;
    esp = esp - 0x34;
    asm { fstp       tword [esp+0x34+var_1C] };
    asm { fstp       tword [esp+0x34+var_34] };
    if ((var_2E & 0x7fff0000) != 0x0) {
            eax = sub_48d716(var_34, var_30, var_2E, var_28, decomp_var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10, var_C, decomp_var_8);
    }
    else {
            asm { fld        tword [esp+0x34+var_34] };
            asm { fld        tword [esp+0x34+var_1C] };
            eax = var_34 | var_30;
            if (eax != 0x0) {
                    edx = 0x0;
                    asm { fxch       st0, st1 };
                    asm { fstp       tword [esp+0x34+var_28] };
                    asm { fld        tword [esp+0x34+var_34] };
                    asm { fxch       st0, st1 };
                    edx = edx | 0x2;
                    asm { fnstcw     word [esp+0x34+var_10] };
                    var_C = var_10 | 0x33f;
                    asm { fldcw      word [esp+0x34+var_C] };
                    if ((var_14 & 0x7fff) <= 0x7fbe) {
                            asm { fmul       qword [qword_4c9e24] };
                            asm { fstp       tword [esp+0x34+var_1C] };
                            asm { fmul       qword [qword_4c9e24] };
                            asm { fstp       tword [esp+0x34+var_34] };
                    }
                    else {
                            asm { fnstcw     word [esp+0x34+var_10] };
                            var_C = var_10 | 0x300;
                            asm { fldcw      word [esp+0x34+var_C] };
                            asm { fstp       st0 };
                            asm { fmul       qword [qword_4c9e24] };
                            asm { fstp       tword [esp+0x34+var_34] };
                    }
                    asm { fldcw      word [esp+0x34+var_10] };
                    eax = sub_48d716(var_34, var_30, var_2E, var_28, decomp_var_24, decomp_var_20, var_1C, decomp_var_18, var_14, var_10, var_C, decomp_var_8);
            }
            else {
                    asm { fprem };
            }
    }
    return eax;
}
