// ComputeInfluenceMatrix @ 0x40d8c0
// hopper name: sub_40d8c0
// pybert name: ComputeInfluenceMatrix
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ComputeInfluenceMatrix() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_2c = ebx;
    decomp_var_30 = ebp;
    decomp_var_34 = esi;
    esp = esp - 0x38;
    decomp_var_38 = edi;
    ebx = arg_0[0x2424] & 0xff;
    eax = arg_0[0x901];
    var_24 = ecx;
    var_4 = ebx;
    if (eax > 0x0) {
            edi = 0x0;
            asm { fld        qword [qword_value_4618441417868443648] };
            var_20 = edi;
            do {
                    esi = 0x0;
                    if (eax > 0x0) {
                            eax = var_20;
                            do {
                                    if (ebx == edi) {
                                            asm { fld        qword [eax+0xb81228] };
                                            asm { fstp       qword [eax+0xb81ff0] };
                                            esi = esi + 0x1;
                                            eax = eax + 0x8;
                                            if (esi < arg_0[0x901]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if (ebx == esi) {
                                            asm { fld        qword [eax+0xb81228] };
                                            asm { fstp       qword [eax+0xb81ff0] };
                                            esi = esi + 0x1;
                                            eax = eax + 0x8;
                                            if (esi < arg_0[0x901]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    ecx = eax[0x13554b];
                                    bool_39 = ecx > 0x0;
                                    edx = eax[0x13554a];
                                    if (ecx < 0x0) {
                                            asm { fild       qword [esp+0x38+var_10] };
                                            asm { fdivr      qword [eax+0xb81228] };
                                            asm { fstp       qword [eax+0xb81ff0] };
                                            esi = esi + 0x1;
                                            eax = eax + 0x8;
                                            if (esi < arg_0[0x901]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if (bool_39) {
                                            asm { fld        qword [eax+0xb81228] };
                                            asm { fdiv       st1 };
                                            asm { fstp       qword [eax+0xb81ff0] };
                                            esi = esi + 0x1;
                                            eax = eax + 0x8;
                                            if (esi < arg_0[0x901]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    if (edx > 0x5) {
                                            asm { fld        qword [eax+0xb81228] };
                                            asm { fdiv       st1 };
                                    }
                                    else {
                                            asm { fild       qword [esp+0x38+var_10] };
                                            asm { fdivr      qword [eax+0xb81228] };
                                    }
                                    asm { fstp       qword [eax+0xb81ff0] };
                                    esi = esi + 0x1;
                                    eax = eax + 0x8;
                            } while (esi < arg_0[0x901]);
                    }
                    edx = arg_0;
                    eax = edx[0x901];
                    var_20 = var_20 + 0xa8;
                    edi = edi + 0x1;
            } while (edi < eax);
            asm { fstp       st0 };
    }
    eax = arg_0;
    asm { fldz };
    eax = eax[0x901];
    if (eax > 0x0) {
            esi = 0x0;
            var_20 = 0x0;
            ebx = 0xb81ff8;
            do {
                    edi = 0x0;
                    asm { fld        st0 };
                    if (eax >= 0x4) {
                            edx = (eax - 0x4 >> 0x2) + 0x1;
                            ecx = ebx;
                            edi = edx * 0x4;
                            do {
                                    asm { fadd       qword [ecx-8] };
                                    ecx = ecx + 0x20;
                                    edx = edx - 0x1;
                                    bool_45 = edx != 0x0;
                                    asm { fadd       qword [ecx-0x20] };
                                    asm { fadd       qword [ecx-0x18] };
                                    asm { fadd       qword [ecx-0x10] };
                            } while (bool_45);
                    }
                    if (edi < eax) {
                            ecx = (var_20 + edi) * 0x8 + 0xb81ff0;
                            eax = eax - edi;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    eax = sub_47b5f6();
                    var_20 = var_20 + 0x15;
                    *(esi * 0x8 + 0x4f6af0) = eax;
                    *(esi * 0x8 + 0x4f6af4) = edx;
                    edx = arg_0;
                    eax = edx[0x901];
                    esi = esi + 0x1;
                    ebx = ebx + 0xa8;
            } while (esi < eax);
    }
    eax = arg_0;
    asm { fld        qword [qword_value_4636737291354636288] };
    eax = eax[0x901];
    ebx = 0x0;
    if (eax > 0x0) {
            ebp = 0xb81ff0;
            do {
                    esi = 0x0;
                    if (eax > 0x0) {
                            asm { fstp       st1 };
                            edi = ebp;
                            while (true) {
                                    ecx = *(esi * 0x8 + 0x4f6af0);
                                    asm { fmul       qword [edi] };
                                    asm { fild       qword [esp+0x38+var_10] };
                                    asm { fdivp      st1 };
                                    asm { fld        qword [qword_value_4608083138725491507] };
                                    sub_47b370();
                                    asm { fmul       qword [qword_value_4647503709213818880] };
                                    eax = var_24;
                                    esi = esi + 0x1;
                                    asm { fadd       qword [edi] };
                                    edi = edi + 0x8;
                                    asm { fstp       qword [edi-8] };
                                    if (esi >= *(eax[0x2] + 0x2404)) {
                                            break;
                                    }
                                    asm { fld        qword [qword_value_4636737291354636288] };
                            }
                            asm { fldz };
                            asm { fld        qword [qword_value_4636737291354636288] };
                    }
                    eax = var_24[0x2];
                    eax = eax[0x901];
                    ebx = ebx + 0x1;
                    ebp = &arg_a0;
            } while (ebx < eax);
    }
    edx = var_24[0x2];
    edx = edx[0x901];
    if (edx > 0x0) {
            edi = 0x0;
            ebx = 0xb81ff8;
            do {
                    esi = 0x0;
                    asm { fld        st1 };
                    if (edx >= 0x4) {
                            ecx = (edx - 0x4 >> 0x2) + 0x1;
                            eax = ebx;
                            esi = ecx * 0x4;
                            do {
                                    asm { fadd       qword [eax-8] };
                                    eax = eax + 0x20;
                                    ecx = ecx - 0x1;
                                    bool_52 = ecx != 0x0;
                                    asm { fadd       qword [eax-0x20] };
                                    asm { fadd       qword [eax-0x18] };
                                    asm { fadd       qword [eax-0x10] };
                            } while (bool_52);
                    }
                    if (esi < edx) {
                            ecx = (edi + esi) * 0x8 + 0xb81ff0;
                            eax = edx - esi;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    ecx = 0x0;
                    bool_49 = edx <= 0x0;
                    edx = var_24;
                    if (!bool_49) {
                            asm { fld        st2 };
                            asm { fucomp     st1 };
                            asm { fnstsw     ax };
                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                    eax = edi + ecx;
                                    asm { fld        qword [dword_633f14+5562588+eax*8] };
                                    asm { fmul       st2 };
                                    asm { fdiv       st1 };
                                    asm { fstp       qword [dword_633f14+5562588+eax*8] };
                            }
                            eax = edx[0x2];
                            ecx = ecx + 0x1;
                            if (ecx < eax[0x901]) {
                                    continue;
                            }
                            break;
                    }
                    ecx = edx[0x2];
                    asm { fstp       st0 };
                    edx = ecx[0x901];
                    ebx = ebx + 0xa8;
                    edi = edi + 0x15;
            } while (&decomp_var_m1 < edx);
    }
    edx = var_24;
    asm { fstp       st0 };
    eax = edx[0x2];
    asm { fstp       st0 };
    esi = 0x0;
    if (eax[0x901] > 0x0) {
            ebp = var_4;
            edx = 0x6340c0;
            edi = 0x633f1c;
            do {
                    *(edi - 0x4) = ebp;
                    *edi = ebp;
                    edi[0x1] = ebp;
                    edi[0x2] = ebp;
                    edi[0x3] = ebp;
                    eax = 0x0;
                    if (*(var_24[0x2] + 0x2404) > 0x0) {
                            ecx = edx;
                            do {
                                    ebx = esi != eax ? 0x1 : 0x0;
                                    eax = eax + 0x1;
                                    ecx = ecx + 0x4;
                                    *(ecx - 0x4) = ebx - 0x2;
                            } while (eax < *(var_24[0x2] + 0x2404));
                    }
                    esi = esi + 0x1;
                    edi = edi + 0x14;
                    edx = edx + 0x54;
            } while (esi < *(var_24[0x2] + 0x2404));
    }
    edi = *(var_24[0x2] + 0x2404);
    eax = 0x0;
    var_4 = 0x0;
    if (edi > 0x0) {
            eax = 0x0;
            asm { fld        qword [qword_value_13830554455654793216] };
            ebx = var_4;
            var_14 = eax;
            var_20 = eax;
            var_18 = 0x6340c4;
            var_1C = 0xb81ff8;
            do {
                    var_10 = 0x1;
                    if (edi > 0x0) {
                            do {
                                    ecx = 0x0;
                                    asm { fld        st0 };
                                    if (edi >= 0x4) {
                                            edx = var_1C;
                                            esi = var_18;
                                            ebp = edi - 0x3;
                                            do {
                                                    asm { fcom       qword [edx-8] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5) && *(esi - 0x4) == 0xffffffff) {
                                                            asm { fstp       st0 };
                                                            ebx = ecx;
                                                            asm { fld        qword [edx-8] };
                                                    }
                                                    asm { fcom       qword [edx] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5) && *esi == 0xffffffff) {
                                                            asm { fstp       st0 };
                                                            ebx = ecx + 0x1;
                                                            asm { fld        qword [edx] };
                                                    }
                                                    asm { fcom       qword [edx+8] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5) && esi[0x1] == 0xffffffff) {
                                                            asm { fstp       st0 };
                                                            ebx = ecx + 0x2;
                                                            asm { fld        qword [edx+8] };
                                                    }
                                                    asm { fcom       qword [edx+0x10] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5) && esi[0x2] == 0xffffffff) {
                                                            asm { fstp       st0 };
                                                            ebx = ecx + 0x3;
                                                            asm { fld        qword [edx+0x10] };
                                                    }
                                                    ecx = ecx + 0x4;
                                                    esi = esi + 0x10;
                                                    edx = edx + 0x20;
                                            } while (ecx < ebp);
                                    }
                                    if (ecx < edi) {
                                            eax = var_20 + ecx;
                                            edx = eax * 0x8 + 0xb81ff0;
                                            esi = eax * 0x4 + 0x6340c0;
                                            do {
                                                    asm { fcom       qword [edx] };
                                                    asm { fnstsw     ax };
                                                    if (!PARITY(HIBYTE(eax) & 0x5) && *esi == 0xffffffff) {
                                                            asm { fstp       st0 };
                                                            ebx = ecx;
                                                            asm { fld        qword [edx] };
                                                    }
                                                    ecx = ecx + 0x1;
                                                    esi = esi + 0x4;
                                                    edx = edx + 0x8;
                                            } while (ecx < edi);
                                    }
                                    eax = var_10;
                                    asm { fstp       st0 };
                                    if (eax < edi) {
                                            *((var_20 + ebx) * 0x4 + 0x6340c0) = eax;
                                            *((var_14 + eax) * 0x4 + 0x633f18) = ebx;
                                    }
                                    edi = *(var_24[0x2] + 0x2404);
                                    var_10 = eax + 0x1;
                                    eax = eax + 0x1 - 0x1;
                            } while (eax < edi);
                    }
                    edi = *(var_24[0x2] + 0x2404);
                    var_1C = var_1C + 0xa8;
                    var_18 = var_18 + 0x54;
                    var_20 = var_20 + 0x15;
                    var_14 = var_14 + 0x5;
                    eax = var_4 + 0x1;
                    var_4 = eax;
            } while (eax < edi);
            asm { fstp       st0 };
    }
    &decomp_var_28 = decomp_var_30;
    return eax;
}
