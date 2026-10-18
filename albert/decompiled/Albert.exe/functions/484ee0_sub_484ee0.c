// sub_484ee0 @ 0x484ee0
// hopper name: sub_484ee0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_484ee0() {
    asm { fldz };
    esp = esp - 0x4;
    decomp_var_4 = esi;
    asm { fcom       qword [ebp+arg_0] };
    esi = 0x0;
    asm { fnstsw     ax };
    asm { fld        qword [ebp+arg_0] };
    if ((HIBYTE(eax) & 0x41) == 0x0) {
            asm { fchs };
    }
    if (arg_c == 0x7ff00000) {
            if (arg_8 == 0x0) {
                    eax = 0x7ff00000;
                    asm { fld1 };
                    asm { fcom       st1 };
                    asm { fnstsw     ax };
                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                            asm { fstp       st2 };
                            asm { fstp       st1 };
                            asm { fstp       st0 };
                            asm { fld        qword [qword_4c9f50] };
                            eax = arg_10;
                    }
                    else {
                            eax = 0x7ff00000;
                            asm { fcom       st1 };
                            asm { fnstsw     ax };
                            asm { fstp       st1 };
                            bool_30 = (HIBYTE(eax) & 0x41) != 0x0;
                            eax = arg_10;
                            if (!bool_30) {
                                    asm { fstp       st0 };
                            }
                            else {
                                    asm { fstp       st1 };
                            }
                    }
                    asm { fstp       qword [eax] };
                    eax = 0x0;
            }
            else {
                    bool_34 = arg_4 != 0x7ff00000;
                    asm { fstp       st0 };
                    if (!bool_34) {
                            if (arg_0 == 0x0) {
                                    eax = 0x7ff00000;
                                    asm { fcom       qword [ebp+arg_8] };
                                    asm { fnstsw     ax };
                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                            asm { fcom       qword [ebp+arg_8] };
                                            asm { fnstsw     ax };
                                            bool_38 = (HIBYTE(eax) & 0x41) == 0x0;
                                            eax = arg_10;
                                            if (!bool_38) {
                                                    asm { fstp       st0 };
                                                    asm { fld1 };
                                            }
                                    }
                                    else {
                                            asm { fstp       st0 };
                                            asm { fld        qword [qword_4c9f50] };
                                            eax = arg_10;
                                    }
                                    asm { fstp       qword [eax] };
                                    eax = 0x0;
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = 0x0;
                            }
                    }
                    else {
                            bool_27 = arg_4 != 0xfff00000;
                            asm { fstp       st0 };
                            if (!bool_27) {
                                    if (arg_0 == 0x0) {
                                            ecx = 0xfff00000;
                                            asm { fld        qword [ebp+arg_8] };
                                            esp = esp - 0x8;
                                            var_C = ecx;
                                            asm { fstp       qword [esp+0xc+var_C] };
                                            eax = sub_484e7c(var_C);
                                            asm { fldz };
                                            esp = esp + 0x4;
                                            asm { fcom       qword [ebp+arg_8] };
                                            esp = esp + 0x4;
                                            ecx = eax;
                                            asm { fnstsw     ax };
                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                    bool_26 = ecx != 0x1;
                                                    asm { fstp       st0 };
                                                    asm { fld        qword [qword_4c9f50] };
                                                    if (!bool_26) {
                                                            asm { fchs };
                                                    }
                                            }
                                            else {
                                                    asm { fcom       qword [ebp+arg_8] };
                                                    asm { fnstsw     ax };
                                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                            if (ecx == 0x1) {
                                                                    asm { fstp       st0 };
                                                                    asm { fld        qword [qword_4c9f70] };
                                                            }
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                            asm { fld1 };
                                                    }
                                            }
                                            eax = arg_10;
                                            asm { fstp       qword [eax] };
                                            eax = 0x0;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
    }
    else {
            if (arg_c == 0xfff00000) {
                    if (arg_8 == 0x0) {
                            eax = 0x7ff00000;
                            asm { fld1 };
                            asm { fcom       st1 };
                            asm { fnstsw     ax };
                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                    asm { fstp       st0 };
                                    asm { fstp       st0 };
                                    eax = arg_10;
                                    asm { fstp       qword [eax] };
                                    eax = 0x0;
                            }
                            else {
                                    eax = 0x7ff00000;
                                    asm { fstp       st2 };
                                    asm { fcompp };
                                    asm { fnstsw     ax };
                                    bool_10 = PARITY(HIBYTE(eax) & 0x5);
                                    eax = arg_10;
                                    if (!bool_10) {
                                            asm { fld        qword [qword_4c9f50] };
                                            asm { fstp       qword [eax] };
                                    }
                                    else {
                                            asm { fld        qword [qword_4c9f58] };
                                            esi = 0x0;
                                            asm { fstp       qword [eax] };
                                            esi = esi + 0x1;
                                    }
                                    eax = esi;
                            }
                    }
                    else {
                            bool_13 = arg_4 != 0x7ff00000;
                            asm { fstp       st0 };
                            if (!bool_13) {
                                    if (arg_0 == 0x0) {
                                            eax = 0x7ff00000;
                                            asm { fcom       qword [ebp+arg_8] };
                                            asm { fnstsw     ax };
                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                    eax = 0x7ff00000;
                                                    asm { fcom       qword [ebp+arg_8] };
                                                    asm { fnstsw     ax };
                                                    bool_17 = (HIBYTE(eax) & 0x41) == 0x0;
                                                    eax = arg_10;
                                                    if (!bool_17) {
                                                            asm { fstp       st0 };
                                                            asm { fld1 };
                                                    }
                                            }
                                            else {
                                                    asm { fstp       st0 };
                                                    asm { fld        qword [qword_4c9f50] };
                                                    eax = arg_10;
                                            }
                                            asm { fstp       qword [eax] };
                                            eax = 0x0;
                                    }
                                    else {
                                            asm { fstp       st0 };
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    bool_14 = arg_4 != 0xfff00000;
                                    asm { fstp       st0 };
                                    if (!bool_14) {
                                            if (arg_0 == 0x0) {
                                                    ecx = 0xfff00000;
                                                    asm { fld        qword [ebp+arg_8] };
                                                    esp = esp - 0x8;
                                                    var_C = ecx;
                                                    asm { fstp       qword [esp+0xc+var_C] };
                                                    eax = sub_484e7c(var_C);
                                                    asm { fldz };
                                                    esp = esp + 0x4;
                                                    asm { fcom       qword [ebp+arg_8] };
                                                    esp = esp + 0x4;
                                                    ecx = eax;
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            bool_8 = ecx != 0x1;
                                                            asm { fstp       st0 };
                                                            asm { fld        qword [qword_4c9f50] };
                                                            if (!bool_8) {
                                                                    asm { fchs };
                                                            }
                                                    }
                                                    else {
                                                            asm { fcom       qword [ebp+arg_8] };
                                                            asm { fnstsw     ax };
                                                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                    if (ecx == 0x1) {
                                                                            asm { fstp       st0 };
                                                                            asm { fld        qword [qword_4c9f70] };
                                                                    }
                                                            }
                                                            else {
                                                                    asm { fstp       st0 };
                                                                    asm { fld1 };
                                                            }
                                                    }
                                                    eax = arg_10;
                                                    asm { fstp       qword [eax] };
                                                    eax = 0x0;
                                            }
                                            else {
                                                    eax = 0x0;
                                            }
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                    }
            }
            else {
                    bool_1 = arg_4 != 0x7ff00000;
                    asm { fstp       st0 };
                    if (!bool_1) {
                            if (arg_0 == 0x0) {
                                    eax = 0x7ff00000;
                                    asm { fcom       qword [ebp+arg_8] };
                                    asm { fnstsw     ax };
                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                            asm { fcom       qword [ebp+arg_8] };
                                            asm { fnstsw     ax };
                                            bool_4 = (HIBYTE(eax) & 0x41) == 0x0;
                                            eax = arg_10;
                                            if (!bool_4) {
                                                    asm { fstp       st0 };
                                                    asm { fld1 };
                                            }
                                    }
                                    else {
                                            asm { fstp       st0 };
                                            asm { fld        qword [qword_4c9f50] };
                                            eax = arg_10;
                                    }
                                    asm { fstp       qword [eax] };
                                    eax = 0x0;
                            }
                            else {
                                    asm { fstp       st0 };
                                    eax = 0x0;
                            }
                    }
                    else {
                            bool_24 = arg_4 != 0xfff00000;
                            asm { fstp       st0 };
                            if (!bool_24) {
                                    if (arg_0 == 0x0) {
                                            ecx = 0xfff00000;
                                            asm { fld        qword [ebp+arg_8] };
                                            esp = esp - 0x8;
                                            var_C = ecx;
                                            asm { fstp       qword [esp+0xc+var_C] };
                                            eax = sub_484e7c(var_C);
                                            asm { fldz };
                                            esp = esp + 0x4;
                                            asm { fcom       qword [ebp+arg_8] };
                                            esp = esp + 0x4;
                                            ecx = eax;
                                            asm { fnstsw     ax };
                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                    bool_20 = ecx != 0x1;
                                                    asm { fstp       st0 };
                                                    asm { fld        qword [qword_4c9f50] };
                                                    if (!bool_20) {
                                                            asm { fchs };
                                                    }
                                            }
                                            else {
                                                    asm { fcom       qword [ebp+arg_8] };
                                                    asm { fnstsw     ax };
                                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                            if (ecx == 0x1) {
                                                                    asm { fstp       st0 };
                                                                    asm { fld        qword [qword_4c9f70] };
                                                            }
                                                    }
                                                    else {
                                                            asm { fstp       st0 };
                                                            asm { fld1 };
                                                    }
                                            }
                                            eax = arg_10;
                                            asm { fstp       qword [eax] };
                                            eax = 0x0;
                                    }
                                    else {
                                            eax = 0x0;
                                    }
                            }
                            else {
                                    eax = 0x0;
                            }
                    }
            }
    }
    return eax;
}
