// sub_48dec1 @ 0x48dec1
// hopper name: sub_48dec1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48dec1() {
    asm { fldz };
    asm { fcom       qword [ebp+arg_0] };
    asm { fnstsw     ax };
    if (!PARITY(HIBYTE(eax) & 0x44)) {
            eax = arg_8;
            *eax = 0x0;
    }
    else {
            if ((arg_6 & 0x7ff0) == 0x0) {
                    if ((arg_4 & 0xfffff) == 0x0) {
                            if (arg_0 != 0x0) {
                                    asm { fcomp      qword [ebp+arg_0] };
                                    edx = 0xfffffc03;
                                    asm { fnstsw     ax };
                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                            eax = 0x1;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                                    while ((arg_6 & 0x10) == 0x0) {
                                            arg_4 = arg_4 << 0x1;
                                            if ((arg_0 & 0x80000000) != 0x0) {
                                                    arg_4 = arg_4 | 0x1;
                                            }
                                            arg_0 = arg_0 << 0x1;
                                            edx = edx - 0x1;
                                    }
                                    arg_6 = arg_6 & 0xffef;
                                    ecx = 0x0;
                                    asm { fld        qword [ebp+arg_0] };
                                    decomp_var_4 = ecx;
                                    var_C = ecx;
                                    esp = esp - 0xc;
                                    var_C = ecx;
                                    asm { fstp       qword [esp+0xc+var_C] };
                                    sub_48de3c(var_C, var_C, decomp_var_4);
                                    esp = esp + 0xc;
                                    eax = arg_8;
                                    *eax = edx;
                            }
                            else {
                                    ecx = 0x0;
                                    esp = esp - 0x4;
                                    decomp_var_4 = ecx;
                                    asm { fstp       st0 };
                                    asm { fld        qword [ebp+arg_0] };
                                    var_C = ecx;
                                    esp = esp - 0x8;
                                    var_C = ecx;
                                    asm { fstp       qword [esp+0xc+var_C] };
                                    sub_48de3c(var_C, var_C, decomp_var_4);
                                    esp = esp + 0xc;
                                    edx = (arg_6 >> 0x4 & 0x7ff) - 0x3fe;
                                    eax = arg_8;
                                    *eax = edx;
                            }
                    }
                    else {
                            asm { fcomp      qword [ebp+arg_0] };
                            edx = 0xfffffc03;
                            asm { fnstsw     ax };
                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                    eax = 0x1;
                            }
                            else {
                                    eax = 0x0;
                            }
                            while ((arg_6 & 0x10) == 0x0) {
                                    arg_4 = arg_4 << 0x1;
                                    if ((arg_0 & 0x80000000) != 0x0) {
                                            arg_4 = arg_4 | 0x1;
                                    }
                                    arg_0 = arg_0 << 0x1;
                                    edx = edx - 0x1;
                            }
                            arg_6 = arg_6 & 0xffef;
                            ecx = 0x0;
                            asm { fld        qword [ebp+arg_0] };
                            decomp_var_4 = ecx;
                            var_C = ecx;
                            esp = esp - 0xc;
                            var_C = ecx;
                            asm { fstp       qword [esp+0xc+var_C] };
                            sub_48de3c(var_C, var_C, decomp_var_4);
                            esp = esp + 0xc;
                            eax = arg_8;
                            *eax = edx;
                    }
            }
            else {
                    ecx = 0x0;
                    esp = esp - 0x4;
                    decomp_var_4 = ecx;
                    asm { fstp       st0 };
                    asm { fld        qword [ebp+arg_0] };
                    var_C = ecx;
                    esp = esp - 0x8;
                    var_C = ecx;
                    asm { fstp       qword [esp+0xc+var_C] };
                    sub_48de3c(var_C, var_C, decomp_var_4);
                    esp = esp + 0xc;
                    edx = (arg_6 >> 0x4 & 0x7ff) - 0x3fe;
                    eax = arg_8;
                    *eax = edx;
            }
    }
    return eax;
}
