// sub_47b3cd @ 0x47b3cd
// hopper name: sub_47b3cd
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c0e234496878fb988ab00ce85437a1c482d67a28823dec57c10e9c5ac13abdc8
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47b3cd() {
    ecx = eax;
    esp = esp - 0x4;
    var_4 = eax;
    asm { wait };
    asm { fnstcw     word [esp+0x4+var_4] };
    if (var_4 != 0x27f) {
            eax = sub_484d05(var_4);
    }
    bool_91 = ecx == 0x7ff00000;
    if ((ecx & 0x7ff00000) != 0x7ff00000) {
            eax = sub_484d35();
            if (!bool_91) {
                    if ((eax & 0x7ff00000) != 0x0) {
                            ecx = arg_7 & 0x80;
                            if (ecx == 0x0) {
                                    asm { fyl2x };
                                    eax = sub_484cf0();
                                    if (ecx == 0x1) {
                                            asm { fchs };
                                    }
                                    if (*dword_bc64a0 == 0x0) {
                                            eax = sub_484dd9();
                                    }
                                    else {
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                            else {
                                    asm { fld        st1 };
                                    sub_47b592();
                                    asm { fchs };
                                    if (ecx == 0x0) {
                                            asm { fstp       st0 };
                                            asm { fstp       st0 };
                                            asm { fld        tword [qword_4c9672+46] };
                                            eax = 0x1;
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            asm { fyl2x };
                                            eax = sub_484cf0();
                                            if (ecx == 0x1) {
                                                    asm { fchs };
                                            }
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484dd9();
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            if ((arg_4 & 0xfffff | arg_0) == 0x0) {
                                    asm { fstp       st0 };
                                    eax = arg_c & 0x7fffffff | arg_8;
                                    if (eax != 0x0) {
                                            eax = sub_47b592();
                                            HIBYTE(ecx) = arg_7;
                                            HIBYTE(ecx) = HIBYTE(ecx) >> 0x7;
                                            if ((arg_F & 0x80) != 0x0) {
                                                    asm { fld        tword [dword_4c9634+12] };
                                                    if ((HIBYTE(ecx) & ecx) != 0x0) {
                                                            asm { fchs };
                                                    }
                                                    eax = 0x2;
                                                    if (*dword_bc64a0 == 0x0) {
                                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                            else {
                                                    asm { fldz };
                                                    if ((HIBYTE(ecx) & ecx) != 0x0) {
                                                            asm { fchs };
                                                    }
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            asm { fstp       st0 };
                                            asm { fld1 };
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                            else {
                                    ecx = arg_7 & 0x80;
                                    if (ecx == 0x0) {
                                            asm { fyl2x };
                                            eax = sub_484cf0();
                                            if (ecx == 0x1) {
                                                    asm { fchs };
                                            }
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484dd9();
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            asm { fld        st1 };
                                            sub_47b592();
                                            asm { fchs };
                                            if (ecx == 0x0) {
                                                    asm { fstp       st0 };
                                                    asm { fstp       st0 };
                                                    asm { fld        tword [qword_4c9672+46] };
                                                    eax = 0x1;
                                                    if (*dword_bc64a0 == 0x0) {
                                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                            else {
                                                    asm { fyl2x };
                                                    eax = sub_484cf0();
                                                    if (ecx == 0x1) {
                                                            asm { fchs };
                                                    }
                                                    if (*dword_bc64a0 == 0x0) {
                                                            eax = sub_484dd9();
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    edx = arg_4 & 0xfffff;
                    if ((arg_4 & 0x7ff00000) == 0x7ff00000) {
                            if ((edx | arg_0) == 0x0) {
                                    if (0x0 == 0x0) {
                                            ecx = &decomp_var_78;
                                            decomp_var_7c = ecx;
                                            esp = esp - 0x88;
                                            asm { fstp       qword [esp+0x8c+var_8C] };
                                            asm { fstp       qword [esp+0x8c+var_84] };
                                            asm { wait };
                                            asm { fnsave     dword [ecx+8] };
                                            eax = sub_484ee0(var_8C, var_8C, var_84, var_84, decomp_var_7c);
                                            ecx = decomp_var_7c;
                                            esp = esp + 0x14;
                                            asm { frstor     dword [ecx+8] };
                                            asm { fld        qword [ecx] };
                                            esp = esp + 0x74;
                                            if (eax != 0x0) {
                                                    eax = 0x1;
                                                    if (*dword_bc64a0 == 0x0) {
                                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            asm { faddp      st1 };
                                            eax = 0x7;
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((arg_6 & 0x8) == 0x0) {
                                            asm { faddp      st1 };
                                            eax = 0x7;
                                    }
                                    else {
                                            asm { faddp      st1 };
                                            eax = 0x1;
                                    }
                                    if (*dword_bc64a0 == 0x0) {
                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                    }
                                    else {
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                    }
                    else {
                            if (0x0 == 0x0) {
                                    ecx = &decomp_var_78;
                                    decomp_var_7c = ecx;
                                    esp = esp - 0x88;
                                    asm { fstp       qword [esp+0x8c+var_8C] };
                                    asm { fstp       qword [esp+0x8c+var_84] };
                                    asm { wait };
                                    asm { fnsave     dword [ecx+8] };
                                    eax = sub_484ee0(var_8C, var_8C, var_84, var_84, decomp_var_7c);
                                    ecx = decomp_var_7c;
                                    esp = esp + 0x14;
                                    asm { frstor     dword [ecx+8] };
                                    asm { fld        qword [ecx] };
                                    esp = esp + 0x74;
                                    if (eax != 0x0) {
                                            eax = 0x1;
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                            else {
                                    asm { faddp      st1 };
                                    eax = 0x7;
                                    if (*dword_bc64a0 == 0x0) {
                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                    }
                                    else {
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if ((eax & 0xfffff | arg_8) == 0x0) {
                    sub_484d35();
                    edx = arg_4 & 0xfffff;
                    if ((arg_4 & 0x7ff00000) == 0x7ff00000) {
                            if ((edx | arg_0) == 0x0) {
                                    if (0x0 == 0x0) {
                                            ecx = &decomp_var_78;
                                            decomp_var_7c = ecx;
                                            esp = esp - 0x88;
                                            asm { fstp       qword [esp+0x8c+var_8C] };
                                            asm { fstp       qword [esp+0x8c+var_84] };
                                            asm { wait };
                                            asm { fnsave     dword [ecx+8] };
                                            eax = sub_484ee0(var_8C, var_8C, var_84, var_84, decomp_var_7c);
                                            ecx = decomp_var_7c;
                                            esp = esp + 0x14;
                                            asm { frstor     dword [ecx+8] };
                                            asm { fld        qword [ecx] };
                                            esp = esp + 0x74;
                                            if (eax != 0x0) {
                                                    eax = 0x1;
                                                    if (*dword_bc64a0 == 0x0) {
                                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            asm { faddp      st1 };
                                            eax = 0x7;
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((arg_6 & 0x8) == 0x0) {
                                            asm { faddp      st1 };
                                            eax = 0x7;
                                    }
                                    else {
                                            asm { faddp      st1 };
                                            eax = 0x1;
                                    }
                                    if (*dword_bc64a0 == 0x0) {
                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                    }
                                    else {
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                    }
                    else {
                            if (0x0 == 0x0) {
                                    ecx = &decomp_var_78;
                                    decomp_var_7c = ecx;
                                    esp = esp - 0x88;
                                    asm { fstp       qword [esp+0x8c+var_8C] };
                                    asm { fstp       qword [esp+0x8c+var_84] };
                                    asm { wait };
                                    asm { fnsave     dword [ecx+8] };
                                    eax = sub_484ee0(var_8C, var_8C, var_84, var_84, decomp_var_7c);
                                    ecx = decomp_var_7c;
                                    esp = esp + 0x14;
                                    asm { frstor     dword [ecx+8] };
                                    asm { fld        qword [ecx] };
                                    esp = esp + 0x74;
                                    if (eax != 0x0) {
                                            eax = 0x1;
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                            else {
                                    asm { faddp      st1 };
                                    eax = 0x7;
                                    if (*dword_bc64a0 == 0x0) {
                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                    }
                                    else {
                                            if (var_4 != 0x27f) {
                                                    asm { fldcw      word [esp+0x4+var_4] };
                                            }
                                    }
                            }
                    }
            }
            else {
                    sub_484d35();
                    if ((arg_E & 0x8) == 0x0) {
                            edx = arg_4 & 0xfffff;
                            if ((arg_4 & 0x7ff00000) == 0x7ff00000) {
                                    if ((edx | arg_0) == 0x0) {
                                            if (0x1 == 0x0) {
                                                    ecx = &decomp_var_78;
                                                    decomp_var_7c = ecx;
                                                    esp = esp - 0x88;
                                                    asm { fstp       qword [esp+0x8c+var_8C] };
                                                    asm { fstp       qword [esp+0x8c+var_84] };
                                                    asm { wait };
                                                    asm { fnsave     dword [ecx+8] };
                                                    eax = sub_484ee0(var_8C, var_8C, var_84, var_84, decomp_var_7c);
                                                    ecx = decomp_var_7c;
                                                    esp = esp + 0x14;
                                                    asm { frstor     dword [ecx+8] };
                                                    asm { fld        qword [ecx] };
                                                    esp = esp + 0x74;
                                                    if (eax != 0x0) {
                                                            eax = 0x1;
                                                            if (*dword_bc64a0 == 0x0) {
                                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                                            }
                                                            else {
                                                                    if (var_4 != 0x27f) {
                                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                            else {
                                                    asm { faddp      st1 };
                                                    eax = 0x7;
                                                    if (*dword_bc64a0 == 0x0) {
                                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((arg_6 & 0x8) == 0x0) {
                                                    asm { faddp      st1 };
                                                    eax = 0x7;
                                            }
                                            else {
                                                    asm { faddp      st1 };
                                                    eax = 0x1;
                                            }
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if (0x1 == 0x0) {
                                            ecx = &decomp_var_78;
                                            decomp_var_7c = ecx;
                                            esp = esp - 0x88;
                                            asm { fstp       qword [esp+0x8c+var_8C] };
                                            asm { fstp       qword [esp+0x8c+var_84] };
                                            asm { wait };
                                            asm { fnsave     dword [ecx+8] };
                                            eax = sub_484ee0(var_8C, var_8C, var_84, var_84, decomp_var_7c);
                                            ecx = decomp_var_7c;
                                            esp = esp + 0x14;
                                            asm { frstor     dword [ecx+8] };
                                            asm { fld        qword [ecx] };
                                            esp = esp + 0x74;
                                            if (eax != 0x0) {
                                                    eax = 0x1;
                                                    if (*dword_bc64a0 == 0x0) {
                                                            eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                                    }
                                                    else {
                                                            if (var_4 != 0x27f) {
                                                                    asm { fldcw      word [esp+0x4+var_4] };
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                                    else {
                                            asm { faddp      st1 };
                                            eax = 0x7;
                                            if (*dword_bc64a0 == 0x0) {
                                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                                            }
                                            else {
                                                    if (var_4 != 0x27f) {
                                                            asm { fldcw      word [esp+0x4+var_4] };
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            asm { faddp      st1 };
                            eax = 0x1;
                            if (*dword_bc64a0 == 0x0) {
                                    eax = sub_484c90(var_4, saved_fp, arg_0, arg_4, arg_8, arg_c);
                            }
                            else {
                                    if (var_4 != 0x27f) {
                                            asm { fldcw      word [esp+0x4+var_4] };
                                    }
                            }
                    }
            }
    }
    return eax;
}
