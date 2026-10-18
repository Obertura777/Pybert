// sub_48dda8 @ 0x48dda8
// hopper name: sub_48dda8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_48dda8() {
    eax = arg_6;
    edx = eax & 0x7ff0;
    if (edx == 0x7ff0) {
            ecx = 0x7ff0;
            asm { fld        qword [ebp+arg_0] };
            var_8 = ecx;
            esp = esp - 0x8;
            var_8 = ecx;
            asm { fstp       qword [esp+0x8+var_8] };
            eax = sub_48de66(var_8, var_8);
            eax = eax - 0x1;
            esp = esp + 0x8;
            if (eax != 0x0) {
                    eax = eax - 0x1;
                    if (eax != 0x0) {
                            if (eax != 0x1) {
                                    eax = 0x1;
                            }
                            else {
                                    esp = esp - 0x4;
                                    var_8 = 0x2;
                                    eax = var_8;
                            }
                    }
                    else {
                            esp = esp - 0x4;
                            var_8 = 0x4;
                            eax = var_8;
                    }
            }
            else {
                    eax = 0x200;
            }
    }
    else {
            eax = eax & 0x8000;
            ecx = eax;
            if (edx == 0x0) {
                    if ((arg_4 & 0xfffff) == 0x0) {
                            if (arg_0 != 0x0) {
                                    eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xffffff90) + 0x80;
                            }
                            else {
                                    asm { fldz };
                                    asm { fcomp      qword [ebp+arg_0] };
                                    asm { fnstsw     ax };
                                    bool_8 = PARITY(HIBYTE(eax) & 0x44);
                                    eax = ecx;
                                    if (!bool_8) {
                                            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xffffffe0) + 0x40;
                                    }
                                    else {
                                            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xffffff08) + 0x100;
                                    }
                            }
                    }
                    else {
                            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xffffff90) + 0x80;
                    }
            }
            else {
                    asm { fldz };
                    asm { fcomp      qword [ebp+arg_0] };
                    asm { fnstsw     ax };
                    bool_5 = PARITY(HIBYTE(eax) & 0x44);
                    eax = ecx;
                    if (!bool_5) {
                            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xffffffe0) + 0x40;
                    }
                    else {
                            eax = (-eax - -eax + CARRY(EFLAGS(cf)) & 0xffffff08) + 0x100;
                    }
            }
    }
    return eax;
}
