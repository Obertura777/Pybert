// sub_445d10 @ 0x445d10
// hopper name: sub_445d10
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_445d10() {

sub_445d10:
    if (ebx == arg_34[0x1]) {
            sub_47a948();
    }
    esi = ebx[0x6];
    eax = ebx + 0x14;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (ebp == esi) goto .l1;
    goto .l2;

.l1:
    eax = (null)();
    return eax;

.l2:
    eax = arg_18[0x2];
    arg_28 = eax + 0x2474;
    arg_50 = eax[0x91e];
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebp == edi[0x1]) {
            sub_47a948();
    }
    ecx = arg_18[0x2];
    edx = ecx[0x91e];
    eax = edx[0x1];
    ecx = ecx + 0x2474;
    edi = &arg_c;
    if (eax[0x19] != 0x0) goto loc_445da9;
    goto loc_445d85;

loc_445da9:
    ebx = ecx[0x1];
    arg_3c = ecx;
    if (edx != ebx) {
            eax = *edi;
            esi = edx[0x3];
            bool_9 = eax != esi;
            if (eax >= esi) {
                    if (!bool_9 && edi[0x2] < edx[0x8]) {
                            arg_44 = ecx;
                            eax = &arg_44;
                    }
                    else {
                            eax = &arg_3c;
                    }
            }
            else {
                    arg_44 = ecx;
                    eax = &arg_44;
            }
    }
    else {
            arg_44 = ecx;
            eax = &arg_44;
    }
    ecx = *eax;
    esi = eax[0x1];
    if (ecx == 0x0 || ecx != arg_28) {
            eax = sub_47a948();
    }
    if (esi != arg_50) {
            if (ebp == arg_2c[0x1]) {
                    eax = sub_47a948();
            }
            asm { fld        qword [ebp+0x20] };
            asm { fld        qword [qword_value_4629137466983448576] };
            asm { fcom       st1 };
            asm { fnstsw     ax };
            if (!PARITY(HIBYTE(eax) & 0x5)) {
                    asm { fstp       st1 };
            }
            else {
                    asm { fstp       st0 };
            }
            asm { fdivr      qword [qword_value_4666723172467343360] };
            asm { fadd       dword [esp+arg_10] };
            asm { fstp       dword [esp+arg_10] };
    }
    if (ebp == arg_2c[0x1]) {
            sub_47a948();
    }
    eax = *edi;
    esi = arg_1c << 0x8;
    eax = eax + esi;
    if (*(eax * 0x8 + 0x520ce8) == 0x1 && *(eax * 0x8 + 0x520cec) == 0x0) {
            if (ebp == arg_2c[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            ebx = sub_407720(edi);
            if (ebp == arg_2c[0x1]) {
                    sub_47a948();
            }
            if (arg_10 == ebx[0x2]) {
                    if (ebp == arg_2c[0x1]) {
                            sub_47a948();
                    }
                    asm { fld        qword [qword_value_4666723172467343360] };
                    asm { fdiv       qword [ebp+0x20] };
                    asm { fadd       dword [esp+arg_10] };
                    asm { fstp       dword [esp+arg_10] };
            }
    }
    if (ebp == arg_2c[0x1]) {
            sub_47a948();
    }
    eax = *edi;
    eax = eax + esi;
    if (*(eax * 0x8 + 0x5164e8) == 0x1 && *(eax * 0x8 + 0x5164ec) == 0x0) {
            if (ebp == arg_2c[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            ebx = sub_407720(edi);
            if (ebp == arg_2c[0x1]) {
                    sub_47a948();
            }
            if (arg_10 == ebx[0x2]) {
                    eax = ebx[0x2];
                    ecx = arg_20;
                    if (eax == ecx || ecx == 0x14 && eax != arg_1c) {
                            if (ebp == arg_2c[0x1]) {
                                    sub_47a948();
                                    ecx = arg_20;
                            }
                            asm { fld        qword [qword_value_4666723172467343360] };
                            asm { fdiv       qword [ebp+0x20] };
                            asm { fadd       dword [esp+arg_14] };
                            asm { fstp       dword [esp+arg_14] };
                    }
                    if (ecx == arg_1c) {
                            if (ebp == arg_2c[0x1]) {
                                    sub_47a948();
                            }
                            eax = *edi;
                            eax = eax + esi;
                            if (*(eax * 0x8 + 0x50bce8) == 0x1) {
                                    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
                                            if (ebp == arg_2c[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = *edi;
                                            eax = eax + esi;
                                            if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
                                                    eax = arg_1c * 0x15 + ebx[0x2];
                                                    bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                    if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                            if (!bool_32) {
                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                            if (ebp == arg_2c[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                                            asm { fdiv       qword [ebp+0x20] };
                                                                            asm { fadd       dword [esp+arg_14] };
                                                                            asm { fstp       dword [esp+arg_14] };
                                                                    }
                                                            }
                                                            else {
                                                                    if (ebp == arg_2c[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                    asm { fadd       dword [esp+arg_14] };
                                                                    asm { fstp       dword [esp+arg_14] };
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            eax = arg_1c * 0x15 + ebx[0x2];
                                            bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                    if (!bool_32) {
                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                    if (ebp == arg_2c[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                    asm { fadd       dword [esp+arg_14] };
                                                                    asm { fstp       dword [esp+arg_14] };
                                                            }
                                                    }
                                                    else {
                                                            if (ebp == arg_2c[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                            asm { fdiv       qword [ebp+0x20] };
                                                            asm { fadd       dword [esp+arg_14] };
                                                            asm { fstp       dword [esp+arg_14] };
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if (ebp == arg_2c[0x1]) {
                                            sub_47a948();
                                    }
                                    eax = *edi;
                                    eax = eax + esi;
                                    if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
                                            eax = arg_1c * 0x15 + ebx[0x2];
                                            bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                    if (!bool_32) {
                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                    if (ebp == arg_2c[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                    asm { fadd       dword [esp+arg_14] };
                                                                    asm { fstp       dword [esp+arg_14] };
                                                            }
                                                    }
                                                    else {
                                                            if (ebp == arg_2c[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                            asm { fdiv       qword [ebp+0x20] };
                                                            asm { fadd       dword [esp+arg_14] };
                                                            asm { fstp       dword [esp+arg_14] };
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    else {
            if (ebp == arg_2c[0x1]) {
                    sub_47a948();
            }
            eax = *edi;
            eax = eax + esi;
            if (*(eax * 0x8 + 0x50bce8) == 0x1 && *(eax * 0x8 + 0x50bcec) == 0x0) {
                    if (ebp == arg_2c[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    ebx = sub_407720(edi);
                    if (ebp == arg_2c[0x1]) {
                            sub_47a948();
                    }
                    if (arg_10 == ebx[0x2]) {
                            eax = ebx[0x2];
                            ecx = arg_20;
                            if (eax == ecx || ecx == 0x14 && eax != arg_1c) {
                                    if (ebp == arg_2c[0x1]) {
                                            sub_47a948();
                                            ecx = arg_20;
                                    }
                                    asm { fld        qword [qword_value_4666723172467343360] };
                                    asm { fdiv       qword [ebp+0x20] };
                                    asm { fadd       dword [esp+arg_14] };
                                    asm { fstp       dword [esp+arg_14] };
                            }
                            if (ecx == arg_1c) {
                                    if (ebp == arg_2c[0x1]) {
                                            sub_47a948();
                                    }
                                    eax = *edi;
                                    eax = eax + esi;
                                    if (*(eax * 0x8 + 0x50bce8) == 0x1) {
                                            if (*(eax * 0x8 + 0x50bcec) != 0x0) {
                                                    if (ebp == arg_2c[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    eax = *edi;
                                                    eax = eax + esi;
                                                    if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
                                                            eax = arg_1c * 0x15 + ebx[0x2];
                                                            bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                                    if (!bool_32) {
                                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                    if (ebp == arg_2c[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                                    asm { fadd       dword [esp+arg_14] };
                                                                                    asm { fstp       dword [esp+arg_14] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (ebp == arg_2c[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                                            asm { fdiv       qword [ebp+0x20] };
                                                                            asm { fadd       dword [esp+arg_14] };
                                                                            asm { fstp       dword [esp+arg_14] };
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    eax = arg_1c * 0x15 + ebx[0x2];
                                                    bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                    if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                            if (!bool_32) {
                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                            if (ebp == arg_2c[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                                            asm { fdiv       qword [ebp+0x20] };
                                                                            asm { fadd       dword [esp+arg_14] };
                                                                            asm { fstp       dword [esp+arg_14] };
                                                                    }
                                                            }
                                                            else {
                                                                    if (ebp == arg_2c[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                    asm { fadd       dword [esp+arg_14] };
                                                                    asm { fstp       dword [esp+arg_14] };
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if (ebp == arg_2c[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = *edi;
                                            eax = eax + esi;
                                            if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
                                                    eax = arg_1c * 0x15 + ebx[0x2];
                                                    bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                    if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                            if (!bool_32) {
                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                            if (ebp == arg_2c[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                                            asm { fdiv       qword [ebp+0x20] };
                                                                            asm { fadd       dword [esp+arg_14] };
                                                                            asm { fstp       dword [esp+arg_14] };
                                                                    }
                                                            }
                                                            else {
                                                                    if (ebp == arg_2c[0x1]) {
                                                                            sub_47a948();
                                                                    }
                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                    asm { fadd       dword [esp+arg_14] };
                                                                    asm { fstp       dword [esp+arg_14] };
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
            else {
                    if (ebp == arg_2c[0x1]) {
                            sub_47a948();
                    }
                    eax = *edi;
                    eax = eax + esi;
                    if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
                            if (ebp == arg_2c[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            ebx = sub_407720(edi);
                            if (ebp == arg_2c[0x1]) {
                                    sub_47a948();
                            }
                            if (arg_10 == ebx[0x2]) {
                                    eax = ebx[0x2];
                                    ecx = arg_20;
                                    if (eax == ecx || ecx == 0x14 && eax != arg_1c) {
                                            if (ebp == arg_2c[0x1]) {
                                                    sub_47a948();
                                                    ecx = arg_20;
                                            }
                                            asm { fld        qword [qword_value_4666723172467343360] };
                                            asm { fdiv       qword [ebp+0x20] };
                                            asm { fadd       dword [esp+arg_14] };
                                            asm { fstp       dword [esp+arg_14] };
                                    }
                                    if (ecx == arg_1c) {
                                            if (ebp == arg_2c[0x1]) {
                                                    sub_47a948();
                                            }
                                            eax = *edi;
                                            eax = eax + esi;
                                            if (*(eax * 0x8 + 0x50bce8) == 0x1) {
                                                    if (*(eax * 0x8 + 0x50bcec) != 0x0) {
                                                            if (ebp == arg_2c[0x1]) {
                                                                    sub_47a948();
                                                            }
                                                            eax = *edi;
                                                            eax = eax + esi;
                                                            if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
                                                                    eax = arg_1c * 0x15 + ebx[0x2];
                                                                    bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                                    if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                                            if (!bool_32) {
                                                                                    if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                            if (ebp == arg_2c[0x1]) {
                                                                                                    sub_47a948();
                                                                                            }
                                                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                                                            asm { fdiv       qword [ebp+0x20] };
                                                                                            asm { fadd       dword [esp+arg_14] };
                                                                                            asm { fstp       dword [esp+arg_14] };
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (ebp == arg_2c[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                                    asm { fadd       dword [esp+arg_14] };
                                                                                    asm { fstp       dword [esp+arg_14] };
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            eax = arg_1c * 0x15 + ebx[0x2];
                                                            bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                                    if (!bool_32) {
                                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                    if (ebp == arg_2c[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                                    asm { fadd       dword [esp+arg_14] };
                                                                                    asm { fstp       dword [esp+arg_14] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (ebp == arg_2c[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                                            asm { fdiv       qword [ebp+0x20] };
                                                                            asm { fadd       dword [esp+arg_14] };
                                                                            asm { fstp       dword [esp+arg_14] };
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (ebp == arg_2c[0x1]) {
                                                            sub_47a948();
                                                    }
                                                    eax = *edi;
                                                    eax = eax + esi;
                                                    if (*(eax * 0x8 + 0x4f6ce8) == 0x1 && *(eax * 0x8 + 0x4f6cec) == 0x0) {
                                                            eax = arg_1c * 0x15 + ebx[0x2];
                                                            bool_32 = *(eax * 0x8 + 0x4d552c) < 0x0;
                                                            if (*(eax * 0x8 + 0x4d552c) <= 0x0) {
                                                                    if (!bool_32) {
                                                                            if (*(eax * 0x8 + 0x4d5528) < 0x3) {
                                                                                    if (ebp == arg_2c[0x1]) {
                                                                                            sub_47a948();
                                                                                    }
                                                                                    asm { fld        qword [qword_value_4666723172467343360] };
                                                                                    asm { fdiv       qword [ebp+0x20] };
                                                                                    asm { fadd       dword [esp+arg_14] };
                                                                                    asm { fstp       dword [esp+arg_14] };
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (ebp == arg_2c[0x1]) {
                                                                                    sub_47a948();
                                                                            }
                                                                            asm { fld        qword [qword_value_4666723172467343360] };
                                                                            asm { fdiv       qword [ebp+0x20] };
                                                                            asm { fadd       dword [esp+arg_14] };
                                                                            asm { fstp       dword [esp+arg_14] };
                                                                    }
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
            }
    }
    sub_40f7f0();
    ebp = arg_30;
    edi = arg_2c;
    ebx = arg_38;
    goto sub_445d10;

loc_445d85:
    ebx = *edi;
    goto loc_445d87;

loc_445d87:
    esi = eax[0x3];
    bool_3 = esi != ebx;
    if (esi >= ebx && (bool_3 || eax[0x8] >= edi[0x2])) {
            edx = eax;
            eax = *eax;
    }
    else {
            eax = eax[0x2];
    }
    if (eax[0x19] == 0x0) goto loc_445d87;
}
