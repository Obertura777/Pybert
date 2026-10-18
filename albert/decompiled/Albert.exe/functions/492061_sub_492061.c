// sub_492061 @ 0x492061
// hopper name: sub_492061
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_b7a3947bafdbab0daeb34882f38c1c09c60bef6ec5044244d9901681c4afa102
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_492061() {
    eax = arg_0;
    decomp_var_14 = ebx;
    esp = esp - 0x8;
    decomp_var_18 = esi;
    esi = eax & 0x1f;
    bool_90 = (eax & 0x8) == 0x0;
    var_4 = esi;
    if ((eax & 0x8) != 0x0) {
            if (!bool_90) {
                    sub_4922a8(0x1);
                    esp = (esp - 0x4) + 0x4;
                    esi = esi & 0xfffffff7;
                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                            sub_4922a8(0x20);
                            esp = (esp - 0x4) + 0x4;
                            esi = esi & 0xffffffef;
                    }
                    eax = esi == 0x0 ? 0x1 : 0x0;
            }
            else {
                    if ((eax & 0x4) != 0x0) {
                            if ((arg_8 & 0x4) != 0x0) {
                                    sub_4922a8(0x4);
                                    esp = (esp - 0x4) + 0x4;
                                    esi = esi & 0xfffffffb;
                                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                            sub_4922a8(0x20);
                                            esp = (esp - 0x4) + 0x4;
                                            esi = esi & 0xffffffef;
                                    }
                                    eax = esi == 0x0 ? 0x1 : 0x0;
                            }
                            else {
                                    ebx = 0x1;
                                    if ((0x1 & eax) != 0x0) {
                                            if ((arg_8 & 0x8) != 0x0) {
                                                    sub_4922a8(0x8);
                                                    esp = (esp - 0x4) + 0x4;
                                                    eax = arg_8 & 0xc00;
                                                    switch (eax) {
                                                        case 0:
                                                            asm { fldz };
                                                            ecx = arg_4;
                                                            asm { fcomp      qword [ecx] };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    asm { fld        qword [qword_4c9f50] };
                                                            }
                                                            else {
                                                                    asm { fld        qword [qword_4c9f50] };
                                                                    asm { fchs };
                                                            }
                                                            asm { fstp       qword [ecx] };
                                                            break;
                                                        case 1024:
                                                            asm { fldz };
                                                            ecx = arg_4;
                                                            asm { fcomp      qword [ecx] };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    asm { fld        qword [qword_4c9f60] };
                                                            }
                                                            else {
                                                                    asm { fld        qword [qword_4c9f50] };
                                                                    asm { fchs };
                                                            }
                                                            asm { fstp       qword [ecx] };
                                                            break;
                                                        case 2048:
                                                            asm { fldz };
                                                            ecx = arg_4;
                                                            asm { fcomp      qword [ecx] };
                                                            asm { fnstsw     ax };
                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                    asm { fld        qword [qword_4c9f60] };
                                                                    asm { fchs };
                                                            }
                                                            else {
                                                                    asm { fld        qword [qword_4c9f50] };
                                                            }
                                                            asm { fstp       qword [ecx] };
                                                            break;
                                                        case 3072:
                                                            asm { fldz };
                                                            ecx = arg_4;
                                                            asm { fcomp      qword [ecx] };
                                                            asm { fnstsw     ax };
                                                            asm { fld        qword [qword_4c9f60] };
                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                    asm { fchs };
                                                            }
                                                            asm { fstp       qword [ecx] };
                                                            break;
                                                    }
                                                    esi = esi & 0xfffffffe;
                                                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                                            sub_4922a8(0x20);
                                                            esp = (esp - 0x4) + 0x4;
                                                            esi = esi & 0xffffffef;
                                                    }
                                                    eax = esi == 0x0 ? 0x1 : 0x0;
                                            }
                                            else {
                                                    if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                                            esi = 0x0;
                                                            if ((eax & 0x10) != 0x0) {
                                                                    esi = ebx;
                                                            }
                                                            asm { fldz };
                                                            esp = esp - 0x4;
                                                            decomp_var_1c = edi;
                                                            edi = arg_4;
                                                            asm { fcomp      qword [edi] };
                                                            asm { fnstsw     ax };
                                                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                                                    asm { fld        qword [edi] };
                                                                    decomp_var_20 = &var_8;
                                                                    var_28 = ecx;
                                                                    esp = esp - 0xc;
                                                                    var_28 = ecx;
                                                                    asm { fstp       qword [esp+0x28+var_28] };
                                                                    eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                                                    ecx = var_8;
                                                                    asm { fstp       qword [ebp+var_10] };
                                                                    ecx = ecx + 0xfffffa00;
                                                                    esp = esp + 0xc;
                                                                    if (ecx < 0xfffffbce) {
                                                                            asm { fld        qword [ebp+var_10] };
                                                                            esi = ebx;
                                                                            asm { fmul       qword [qword_value_0] };
                                                                            asm { fstp       qword [ebp+var_10] };
                                                                    }
                                                                    else {
                                                                            asm { fldz };
                                                                            asm { fcomp      qword [ebp+var_10] };
                                                                            asm { fnstsw     ax };
                                                                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                                    edx = ebx;
                                                                            }
                                                                            else {
                                                                                    edx = 0x0;
                                                                            }
                                                                            bool_173 = ecx == 0xfffffc03;
                                                                            if (ecx < 0xfffffc03) {
                                                                                    eax = 0xfffffc03 - ecx;
                                                                                    do {
                                                                                            if (!bool_173 && esi == 0x0) {
                                                                                                    esi = ebx;
                                                                                            }
                                                                                            var_10 = var_10 >> 0x1;
                                                                                            if (var_10 != 0x0) {
                                                                                                    var_10 = var_10 | 0x80000000;
                                                                                            }
                                                                                            var_C = var_C >> 0x1;
                                                                                            eax = eax - 0x1;
                                                                                    } while (eax != 0x0);
                                                                            }
                                                                            if (edx != 0x0) {
                                                                                    asm { fld        qword [ebp+var_10] };
                                                                                    asm { fchs };
                                                                                    asm { fstp       qword [ebp+var_10] };
                                                                            }
                                                                    }
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    asm { fstp       qword [edi] };
                                                            }
                                                            else {
                                                                    esi = ebx;
                                                            }
                                                            esp = esp + 0x4;
                                                            if (esi != 0x0) {
                                                                    sub_4922a8(0x10);
                                                                    esp = (esp - 0x4) + 0x4;
                                                            }
                                                            esi = var_4 & 0xfffffffd;
                                                    }
                                                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                                            sub_4922a8(0x20);
                                                            esp = (esp - 0x4) + 0x4;
                                                            esi = esi & 0xffffffef;
                                                    }
                                                    eax = esi == 0x0 ? 0x1 : 0x0;
                                            }
                                    }
                                    else {
                                            if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                                    esi = 0x0;
                                                    if ((eax & 0x10) != 0x0) {
                                                            esi = ebx;
                                                    }
                                                    asm { fldz };
                                                    esp = esp - 0x4;
                                                    decomp_var_1c = edi;
                                                    edi = arg_4;
                                                    asm { fcomp      qword [edi] };
                                                    asm { fnstsw     ax };
                                                    if (PARITY(HIBYTE(eax) & 0x44)) {
                                                            asm { fld        qword [edi] };
                                                            decomp_var_20 = &var_8;
                                                            var_28 = ecx;
                                                            esp = esp - 0xc;
                                                            var_28 = ecx;
                                                            asm { fstp       qword [esp+0x28+var_28] };
                                                            eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                                            ecx = var_8;
                                                            asm { fstp       qword [ebp+var_10] };
                                                            ecx = ecx + 0xfffffa00;
                                                            esp = esp + 0xc;
                                                            if (ecx < 0xfffffbce) {
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    esi = ebx;
                                                                    asm { fmul       qword [qword_value_0] };
                                                                    asm { fstp       qword [ebp+var_10] };
                                                            }
                                                            else {
                                                                    asm { fldz };
                                                                    asm { fcomp      qword [ebp+var_10] };
                                                                    asm { fnstsw     ax };
                                                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                            edx = ebx;
                                                                    }
                                                                    else {
                                                                            edx = 0x0;
                                                                    }
                                                                    bool_187 = ecx == 0xfffffc03;
                                                                    if (ecx < 0xfffffc03) {
                                                                            eax = 0xfffffc03 - ecx;
                                                                            do {
                                                                                    if (!bool_187 && esi == 0x0) {
                                                                                            esi = ebx;
                                                                                    }
                                                                                    var_10 = var_10 >> 0x1;
                                                                                    if (var_10 != 0x0) {
                                                                                            var_10 = var_10 | 0x80000000;
                                                                                    }
                                                                                    var_C = var_C >> 0x1;
                                                                                    eax = eax - 0x1;
                                                                            } while (eax != 0x0);
                                                                    }
                                                                    if (edx != 0x0) {
                                                                            asm { fld        qword [ebp+var_10] };
                                                                            asm { fchs };
                                                                            asm { fstp       qword [ebp+var_10] };
                                                                    }
                                                            }
                                                            asm { fld        qword [ebp+var_10] };
                                                            asm { fstp       qword [edi] };
                                                    }
                                                    else {
                                                            esi = ebx;
                                                    }
                                                    esp = esp + 0x4;
                                                    if (esi != 0x0) {
                                                            sub_4922a8(0x10);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    esi = var_4 & 0xfffffffd;
                                            }
                                            if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                                    sub_4922a8(0x20);
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi = esi & 0xffffffef;
                                            }
                                            eax = esi == 0x0 ? 0x1 : 0x0;
                                    }
                            }
                    }
                    else {
                            if ((0x1 & eax) != 0x0) {
                                    if ((arg_8 & 0x8) != 0x0) {
                                            sub_4922a8(0x8);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = arg_8 & 0xc00;
                                            switch (eax) {
                                                case 0:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fld        qword [qword_4c9f50] };
                                                    }
                                                    else {
                                                            asm { fld        qword [qword_4c9f50] };
                                                            asm { fchs };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                                case 1024:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fld        qword [qword_4c9f60] };
                                                    }
                                                    else {
                                                            asm { fld        qword [qword_4c9f50] };
                                                            asm { fchs };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                                case 2048:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fld        qword [qword_4c9f60] };
                                                            asm { fchs };
                                                    }
                                                    else {
                                                            asm { fld        qword [qword_4c9f50] };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                                case 3072:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    asm { fld        qword [qword_4c9f60] };
                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fchs };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                            }
                                            esi = esi & 0xfffffffe;
                                            if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                                    sub_4922a8(0x20);
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi = esi & 0xffffffef;
                                            }
                                            eax = esi == 0x0 ? 0x1 : 0x0;
                                    }
                                    else {
                                            if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                                    esi = 0x0;
                                                    if ((eax & 0x10) != 0x0) {
                                                            esi = 0x1;
                                                    }
                                                    asm { fldz };
                                                    esp = esp - 0x4;
                                                    decomp_var_1c = edi;
                                                    edi = arg_4;
                                                    asm { fcomp      qword [edi] };
                                                    asm { fnstsw     ax };
                                                    if (PARITY(HIBYTE(eax) & 0x44)) {
                                                            asm { fld        qword [edi] };
                                                            decomp_var_20 = &var_8;
                                                            var_28 = ecx;
                                                            esp = esp - 0xc;
                                                            var_28 = ecx;
                                                            asm { fstp       qword [esp+0x28+var_28] };
                                                            eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                                            ecx = var_8;
                                                            asm { fstp       qword [ebp+var_10] };
                                                            ecx = ecx + 0xfffffa00;
                                                            esp = esp + 0xc;
                                                            if (ecx < 0xfffffbce) {
                                                                    ebx = 0x1;
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    esi = ebx;
                                                                    asm { fmul       qword [qword_value_0] };
                                                                    asm { fstp       qword [ebp+var_10] };
                                                            }
                                                            else {
                                                                    asm { fldz };
                                                                    asm { fcomp      qword [ebp+var_10] };
                                                                    asm { fnstsw     ax };
                                                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                            edx = 0x1;
                                                                    }
                                                                    else {
                                                                            edx = 0x0;
                                                                    }
                                                                    bool_185 = ecx == 0xfffffc03;
                                                                    if (ecx < 0xfffffc03) {
                                                                            eax = 0xfffffc03 - ecx;
                                                                            do {
                                                                                    if (!bool_185 && esi == 0x0) {
                                                                                            esi = 0x1;
                                                                                    }
                                                                                    var_10 = var_10 >> 0x1;
                                                                                    if (var_10 != 0x0) {
                                                                                            var_10 = var_10 | 0x80000000;
                                                                                    }
                                                                                    var_C = var_C >> 0x1;
                                                                                    eax = eax - 0x1;
                                                                            } while (eax != 0x0);
                                                                    }
                                                                    if (edx != 0x0) {
                                                                            asm { fld        qword [ebp+var_10] };
                                                                            asm { fchs };
                                                                            asm { fstp       qword [ebp+var_10] };
                                                                    }
                                                            }
                                                            asm { fld        qword [ebp+var_10] };
                                                            asm { fstp       qword [edi] };
                                                    }
                                                    else {
                                                            esi = 0x1;
                                                    }
                                                    esp = esp + 0x4;
                                                    if (esi != 0x0) {
                                                            sub_4922a8(0x10);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    esi = var_4 & 0xfffffffd;
                                            }
                                            if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                                    sub_4922a8(0x20);
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi = esi & 0xffffffef;
                                            }
                                            eax = esi == 0x0 ? 0x1 : 0x0;
                                    }
                            }
                            else {
                                    if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                            esi = 0x0;
                                            if ((eax & 0x10) != 0x0) {
                                                    esi = 0x1;
                                            }
                                            asm { fldz };
                                            esp = esp - 0x4;
                                            decomp_var_1c = edi;
                                            edi = arg_4;
                                            asm { fcomp      qword [edi] };
                                            asm { fnstsw     ax };
                                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                                    asm { fld        qword [edi] };
                                                    decomp_var_20 = &var_8;
                                                    var_28 = ecx;
                                                    esp = esp - 0xc;
                                                    var_28 = ecx;
                                                    asm { fstp       qword [esp+0x28+var_28] };
                                                    eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                                    ecx = var_8;
                                                    asm { fstp       qword [ebp+var_10] };
                                                    ecx = ecx + 0xfffffa00;
                                                    esp = esp + 0xc;
                                                    if (ecx < 0xfffffbce) {
                                                            ebx = 0x1;
                                                            asm { fld        qword [ebp+var_10] };
                                                            esi = ebx;
                                                            asm { fmul       qword [qword_value_0] };
                                                            asm { fstp       qword [ebp+var_10] };
                                                    }
                                                    else {
                                                            asm { fldz };
                                                            asm { fcomp      qword [ebp+var_10] };
                                                            asm { fnstsw     ax };
                                                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                    edx = 0x1;
                                                            }
                                                            else {
                                                                    edx = 0x0;
                                                            }
                                                            bool_170 = ecx == 0xfffffc03;
                                                            if (ecx < 0xfffffc03) {
                                                                    eax = 0xfffffc03 - ecx;
                                                                    do {
                                                                            if (!bool_170 && esi == 0x0) {
                                                                                    esi = 0x1;
                                                                            }
                                                                            var_10 = var_10 >> 0x1;
                                                                            if (var_10 != 0x0) {
                                                                                    var_10 = var_10 | 0x80000000;
                                                                            }
                                                                            var_C = var_C >> 0x1;
                                                                            eax = eax - 0x1;
                                                                    } while (eax != 0x0);
                                                            }
                                                            if (edx != 0x0) {
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    asm { fchs };
                                                                    asm { fstp       qword [ebp+var_10] };
                                                            }
                                                    }
                                                    asm { fld        qword [ebp+var_10] };
                                                    asm { fstp       qword [edi] };
                                            }
                                            else {
                                                    esi = 0x1;
                                            }
                                            esp = esp + 0x4;
                                            if (esi != 0x0) {
                                                    sub_4922a8(0x10);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            esi = var_4 & 0xfffffffd;
                                    }
                                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                            sub_4922a8(0x20);
                                            esp = (esp - 0x4) + 0x4;
                                            esi = esi & 0xffffffef;
                                    }
                                    eax = esi == 0x0 ? 0x1 : 0x0;
                            }
                    }
            }
    }
    else {
            if ((eax & 0x4) != 0x0) {
                    if ((arg_8 & 0x4) != 0x0) {
                            sub_4922a8(0x4);
                            esp = (esp - 0x4) + 0x4;
                            esi = esi & 0xfffffffb;
                            if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                    sub_4922a8(0x20);
                                    esp = (esp - 0x4) + 0x4;
                                    esi = esi & 0xffffffef;
                            }
                            eax = esi == 0x0 ? 0x1 : 0x0;
                    }
                    else {
                            if ((0x1 & eax) != 0x0) {
                                    if ((arg_8 & 0x8) != 0x0) {
                                            sub_4922a8(0x8);
                                            esp = (esp - 0x4) + 0x4;
                                            eax = arg_8 & 0xc00;
                                            switch (eax) {
                                                case 0:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fld        qword [qword_4c9f50] };
                                                    }
                                                    else {
                                                            asm { fld        qword [qword_4c9f50] };
                                                            asm { fchs };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                                case 1024:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fld        qword [qword_4c9f60] };
                                                    }
                                                    else {
                                                            asm { fld        qword [qword_4c9f50] };
                                                            asm { fchs };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                                case 2048:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fld        qword [qword_4c9f60] };
                                                            asm { fchs };
                                                    }
                                                    else {
                                                            asm { fld        qword [qword_4c9f50] };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                                case 3072:
                                                    asm { fldz };
                                                    ecx = arg_4;
                                                    asm { fcomp      qword [ecx] };
                                                    asm { fnstsw     ax };
                                                    asm { fld        qword [qword_4c9f60] };
                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                            asm { fchs };
                                                    }
                                                    asm { fstp       qword [ecx] };
                                                    break;
                                            }
                                            esi = esi & 0xfffffffe;
                                            if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                                    sub_4922a8(0x20);
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi = esi & 0xffffffef;
                                            }
                                            eax = esi == 0x0 ? 0x1 : 0x0;
                                    }
                                    else {
                                            if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                                    esi = 0x0;
                                                    if ((eax & 0x10) != 0x0) {
                                                            esi = 0x1;
                                                    }
                                                    asm { fldz };
                                                    esp = esp - 0x4;
                                                    decomp_var_1c = edi;
                                                    edi = arg_4;
                                                    asm { fcomp      qword [edi] };
                                                    asm { fnstsw     ax };
                                                    if (PARITY(HIBYTE(eax) & 0x44)) {
                                                            asm { fld        qword [edi] };
                                                            decomp_var_20 = &var_8;
                                                            var_28 = ecx;
                                                            esp = esp - 0xc;
                                                            var_28 = ecx;
                                                            asm { fstp       qword [esp+0x28+var_28] };
                                                            eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                                            ecx = var_8;
                                                            asm { fstp       qword [ebp+var_10] };
                                                            ecx = ecx + 0xfffffa00;
                                                            esp = esp + 0xc;
                                                            if (ecx < 0xfffffbce) {
                                                                    ebx = 0x1;
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    esi = ebx;
                                                                    asm { fmul       qword [qword_value_0] };
                                                                    asm { fstp       qword [ebp+var_10] };
                                                            }
                                                            else {
                                                                    asm { fldz };
                                                                    asm { fcomp      qword [ebp+var_10] };
                                                                    asm { fnstsw     ax };
                                                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                            edx = 0x1;
                                                                    }
                                                                    else {
                                                                            edx = 0x0;
                                                                    }
                                                                    bool_164 = ecx == 0xfffffc03;
                                                                    if (ecx < 0xfffffc03) {
                                                                            eax = 0xfffffc03 - ecx;
                                                                            do {
                                                                                    if (!bool_164 && esi == 0x0) {
                                                                                            esi = 0x1;
                                                                                    }
                                                                                    var_10 = var_10 >> 0x1;
                                                                                    if (var_10 != 0x0) {
                                                                                            var_10 = var_10 | 0x80000000;
                                                                                    }
                                                                                    var_C = var_C >> 0x1;
                                                                                    eax = eax - 0x1;
                                                                            } while (eax != 0x0);
                                                                    }
                                                                    if (edx != 0x0) {
                                                                            asm { fld        qword [ebp+var_10] };
                                                                            asm { fchs };
                                                                            asm { fstp       qword [ebp+var_10] };
                                                                    }
                                                            }
                                                            asm { fld        qword [ebp+var_10] };
                                                            asm { fstp       qword [edi] };
                                                    }
                                                    else {
                                                            esi = 0x1;
                                                    }
                                                    esp = esp + 0x4;
                                                    if (esi != 0x0) {
                                                            sub_4922a8(0x10);
                                                            esp = (esp - 0x4) + 0x4;
                                                    }
                                                    esi = var_4 & 0xfffffffd;
                                            }
                                            if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                                    sub_4922a8(0x20);
                                                    esp = (esp - 0x4) + 0x4;
                                                    esi = esi & 0xffffffef;
                                            }
                                            eax = esi == 0x0 ? 0x1 : 0x0;
                                    }
                            }
                            else {
                                    if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                            esi = 0x0;
                                            if ((eax & 0x10) != 0x0) {
                                                    esi = 0x1;
                                            }
                                            asm { fldz };
                                            esp = esp - 0x4;
                                            decomp_var_1c = edi;
                                            edi = arg_4;
                                            asm { fcomp      qword [edi] };
                                            asm { fnstsw     ax };
                                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                                    asm { fld        qword [edi] };
                                                    decomp_var_20 = &var_8;
                                                    var_28 = ecx;
                                                    esp = esp - 0xc;
                                                    var_28 = ecx;
                                                    asm { fstp       qword [esp+0x28+var_28] };
                                                    eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                                    ecx = var_8;
                                                    asm { fstp       qword [ebp+var_10] };
                                                    ecx = ecx + 0xfffffa00;
                                                    esp = esp + 0xc;
                                                    if (ecx < 0xfffffbce) {
                                                            ebx = 0x1;
                                                            asm { fld        qword [ebp+var_10] };
                                                            esi = ebx;
                                                            asm { fmul       qword [qword_value_0] };
                                                            asm { fstp       qword [ebp+var_10] };
                                                    }
                                                    else {
                                                            asm { fldz };
                                                            asm { fcomp      qword [ebp+var_10] };
                                                            asm { fnstsw     ax };
                                                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                    edx = 0x1;
                                                            }
                                                            else {
                                                                    edx = 0x0;
                                                            }
                                                            bool_178 = ecx == 0xfffffc03;
                                                            if (ecx < 0xfffffc03) {
                                                                    eax = 0xfffffc03 - ecx;
                                                                    do {
                                                                            if (!bool_178 && esi == 0x0) {
                                                                                    esi = 0x1;
                                                                            }
                                                                            var_10 = var_10 >> 0x1;
                                                                            if (var_10 != 0x0) {
                                                                                    var_10 = var_10 | 0x80000000;
                                                                            }
                                                                            var_C = var_C >> 0x1;
                                                                            eax = eax - 0x1;
                                                                    } while (eax != 0x0);
                                                            }
                                                            if (edx != 0x0) {
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    asm { fchs };
                                                                    asm { fstp       qword [ebp+var_10] };
                                                            }
                                                    }
                                                    asm { fld        qword [ebp+var_10] };
                                                    asm { fstp       qword [edi] };
                                            }
                                            else {
                                                    esi = 0x1;
                                            }
                                            esp = esp + 0x4;
                                            if (esi != 0x0) {
                                                    sub_4922a8(0x10);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            esi = var_4 & 0xfffffffd;
                                    }
                                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                            sub_4922a8(0x20);
                                            esp = (esp - 0x4) + 0x4;
                                            esi = esi & 0xffffffef;
                                    }
                                    eax = esi == 0x0 ? 0x1 : 0x0;
                            }
                    }
            }
            else {
                    if ((0x1 & eax) != 0x0) {
                            if ((arg_8 & 0x8) != 0x0) {
                                    sub_4922a8(0x8);
                                    esp = (esp - 0x4) + 0x4;
                                    eax = arg_8 & 0xc00;
                                    switch (eax) {
                                        case 0:
                                            asm { fldz };
                                            ecx = arg_4;
                                            asm { fcomp      qword [ecx] };
                                            asm { fnstsw     ax };
                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                    asm { fld        qword [qword_4c9f50] };
                                            }
                                            else {
                                                    asm { fld        qword [qword_4c9f50] };
                                                    asm { fchs };
                                            }
                                            asm { fstp       qword [ecx] };
                                            break;
                                        case 1024:
                                            asm { fldz };
                                            ecx = arg_4;
                                            asm { fcomp      qword [ecx] };
                                            asm { fnstsw     ax };
                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                    asm { fld        qword [qword_4c9f60] };
                                            }
                                            else {
                                                    asm { fld        qword [qword_4c9f50] };
                                                    asm { fchs };
                                            }
                                            asm { fstp       qword [ecx] };
                                            break;
                                        case 2048:
                                            asm { fldz };
                                            ecx = arg_4;
                                            asm { fcomp      qword [ecx] };
                                            asm { fnstsw     ax };
                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                    asm { fld        qword [qword_4c9f60] };
                                                    asm { fchs };
                                            }
                                            else {
                                                    asm { fld        qword [qword_4c9f50] };
                                            }
                                            asm { fstp       qword [ecx] };
                                            break;
                                        case 3072:
                                            asm { fldz };
                                            ecx = arg_4;
                                            asm { fcomp      qword [ecx] };
                                            asm { fnstsw     ax };
                                            asm { fld        qword [qword_4c9f60] };
                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                    asm { fchs };
                                            }
                                            asm { fstp       qword [ecx] };
                                            break;
                                    }
                                    esi = esi & 0xfffffffe;
                                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                            sub_4922a8(0x20);
                                            esp = (esp - 0x4) + 0x4;
                                            esi = esi & 0xffffffef;
                                    }
                                    eax = esi == 0x0 ? 0x1 : 0x0;
                            }
                            else {
                                    if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                            esi = 0x0;
                                            if ((eax & 0x10) != 0x0) {
                                                    esi = 0x1;
                                            }
                                            asm { fldz };
                                            esp = esp - 0x4;
                                            decomp_var_1c = edi;
                                            edi = arg_4;
                                            asm { fcomp      qword [edi] };
                                            asm { fnstsw     ax };
                                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                                    asm { fld        qword [edi] };
                                                    decomp_var_20 = &var_8;
                                                    var_28 = ecx;
                                                    esp = esp - 0xc;
                                                    var_28 = ecx;
                                                    asm { fstp       qword [esp+0x28+var_28] };
                                                    eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                                    ecx = var_8;
                                                    asm { fstp       qword [ebp+var_10] };
                                                    ecx = ecx + 0xfffffa00;
                                                    esp = esp + 0xc;
                                                    if (ecx < 0xfffffbce) {
                                                            ebx = 0x1;
                                                            asm { fld        qword [ebp+var_10] };
                                                            esi = ebx;
                                                            asm { fmul       qword [qword_value_0] };
                                                            asm { fstp       qword [ebp+var_10] };
                                                    }
                                                    else {
                                                            asm { fldz };
                                                            asm { fcomp      qword [ebp+var_10] };
                                                            asm { fnstsw     ax };
                                                            if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                                    edx = 0x1;
                                                            }
                                                            else {
                                                                    edx = 0x0;
                                                            }
                                                            bool_179 = ecx == 0xfffffc03;
                                                            if (ecx < 0xfffffc03) {
                                                                    eax = 0xfffffc03 - ecx;
                                                                    do {
                                                                            if (!bool_179 && esi == 0x0) {
                                                                                    esi = 0x1;
                                                                            }
                                                                            var_10 = var_10 >> 0x1;
                                                                            if (var_10 != 0x0) {
                                                                                    var_10 = var_10 | 0x80000000;
                                                                            }
                                                                            var_C = var_C >> 0x1;
                                                                            eax = eax - 0x1;
                                                                    } while (eax != 0x0);
                                                            }
                                                            if (edx != 0x0) {
                                                                    asm { fld        qword [ebp+var_10] };
                                                                    asm { fchs };
                                                                    asm { fstp       qword [ebp+var_10] };
                                                            }
                                                    }
                                                    asm { fld        qword [ebp+var_10] };
                                                    asm { fstp       qword [edi] };
                                            }
                                            else {
                                                    esi = 0x1;
                                            }
                                            esp = esp + 0x4;
                                            if (esi != 0x0) {
                                                    sub_4922a8(0x10);
                                                    esp = (esp - 0x4) + 0x4;
                                            }
                                            esi = var_4 & 0xfffffffd;
                                    }
                                    if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                            sub_4922a8(0x20);
                                            esp = (esp - 0x4) + 0x4;
                                            esi = esi & 0xffffffef;
                                    }
                                    eax = esi == 0x0 ? 0x1 : 0x0;
                            }
                    }
                    else {
                            if ((eax & 0x2) != 0x0 && (arg_8 & 0x10) != 0x0) {
                                    esi = 0x0;
                                    if ((eax & 0x10) != 0x0) {
                                            esi = 0x1;
                                    }
                                    asm { fldz };
                                    esp = esp - 0x4;
                                    decomp_var_1c = edi;
                                    edi = arg_4;
                                    asm { fcomp      qword [edi] };
                                    asm { fnstsw     ax };
                                    if (PARITY(HIBYTE(eax) & 0x44)) {
                                            asm { fld        qword [edi] };
                                            decomp_var_20 = &var_8;
                                            var_28 = ecx;
                                            esp = esp - 0xc;
                                            var_28 = ecx;
                                            asm { fstp       qword [esp+0x28+var_28] };
                                            eax = sub_48dec1(var_28, var_28, decomp_var_20);
                                            ecx = var_8;
                                            asm { fstp       qword [ebp+var_10] };
                                            ecx = ecx + 0xfffffa00;
                                            esp = esp + 0xc;
                                            if (ecx < 0xfffffbce) {
                                                    ebx = 0x1;
                                                    asm { fld        qword [ebp+var_10] };
                                                    esi = ebx;
                                                    asm { fmul       qword [qword_value_0] };
                                                    asm { fstp       qword [ebp+var_10] };
                                            }
                                            else {
                                                    asm { fldz };
                                                    asm { fcomp      qword [ebp+var_10] };
                                                    asm { fnstsw     ax };
                                                    if ((HIBYTE(eax) & 0x41) == 0x0) {
                                                            edx = 0x1;
                                                    }
                                                    else {
                                                            edx = 0x0;
                                                    }
                                                    bool_191 = ecx == 0xfffffc03;
                                                    if (ecx < 0xfffffc03) {
                                                            eax = 0xfffffc03 - ecx;
                                                            do {
                                                                    if (!bool_191 && esi == 0x0) {
                                                                            esi = 0x1;
                                                                    }
                                                                    var_10 = var_10 >> 0x1;
                                                                    if (var_10 != 0x0) {
                                                                            var_10 = var_10 | 0x80000000;
                                                                    }
                                                                    var_C = var_C >> 0x1;
                                                                    eax = eax - 0x1;
                                                            } while (eax != 0x0);
                                                    }
                                                    if (edx != 0x0) {
                                                            asm { fld        qword [ebp+var_10] };
                                                            asm { fchs };
                                                            asm { fstp       qword [ebp+var_10] };
                                                    }
                                            }
                                            asm { fld        qword [ebp+var_10] };
                                            asm { fstp       qword [edi] };
                                    }
                                    else {
                                            esi = 0x1;
                                    }
                                    esp = esp + 0x4;
                                    if (esi != 0x0) {
                                            sub_4922a8(0x10);
                                            esp = (esp - 0x4) + 0x4;
                                    }
                                    esi = var_4 & 0xfffffffd;
                            }
                            if ((arg_0 & 0x10) != 0x0 && (arg_8 & 0x20) != 0x0) {
                                    sub_4922a8(0x20);
                                    esp = (esp - 0x4) + 0x4;
                                    esi = esi & 0xffffffef;
                            }
                            eax = esi == 0x0 ? 0x1 : 0x0;
                    }
            }
    }
    return eax;
}
