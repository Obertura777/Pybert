// sub_40cdc0 @ 0x40cdc0
// hopper name: sub_40cdc0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40cdc0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_14 = ebx;
    ebx = ecx;
    eax = ebx[0x2];
    eax = eax[0x901];
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    edx = 0x0;
    esp = esp - 0x20;
    decomp_var_20 = edi;
    if (eax > 0x0) {
            esi = 0x0;
            do {
                    ecx = 0x0;
                    if (eax > 0x0) {
                            eax = esi;
                            do {
                                    asm { fild       qword [esp+0x20+var_10] };
                                    ecx = ecx + 0x1;
                                    eax = eax + 0x8;
                                    asm { fdivr      qword [eax+0xb81220] };
                                    asm { fstp       qword [eax+0xb82db0] };
                            } while (ecx < *(ebx[0x2] + 0x2404));
                    }
                    eax = *(ebx[0x2] + 0x2404);
                    edx = edx + 0x1;
                    esi = esi + 0xa8;
            } while (edx < eax);
    }
    edx = ebx[0x2];
    asm { fldz };
    eax = edx[0x901];
    if (eax > 0x0) {
            esi = 0x0;
            var_10 = 0x0;
            ebp = 0xb82dc0;
            do {
                    edi = 0x0;
                    asm { fld        st0 };
                    if (eax >= 0x4) {
                            edx = (eax - 0x4 >> 0x2) + 0x1;
                            ecx = ebp;
                            edi = edx * 0x4;
                            do {
                                    asm { fadd       qword [ecx-8] };
                                    ecx = ecx + 0x20;
                                    edx = edx - 0x1;
                                    bool_12 = edx != 0x0;
                                    asm { fadd       qword [ecx-0x20] };
                                    asm { fadd       qword [ecx-0x18] };
                                    asm { fadd       qword [ecx-0x10] };
                            } while (bool_12);
                    }
                    if (edi < eax) {
                            ecx = (var_10 + edi) * 0x8 + 0xb82db8;
                            eax = eax - edi;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    var_10 = var_10 + 0x15;
                    *(esi * 0x8 + 0x4f6b98) = sub_47b5f6();
                    *(esi * 0x8 + 0x4f6b9c) = edx;
                    edx = ebx[0x2];
                    eax = edx[0x901];
                    esi = esi + 0x1;
                    ebp = &arg_a0;
            } while (esi < eax);
    }
    eax = ebx[0x2];
    asm { fld        qword [qword_value_4636737291354636288] };
    eax = eax[0x901];
    if (eax > 0x0) {
            edi = 0xb82db8;
            var_10 = 0xb82db8;
            do {
                    esi = 0x0;
                    if (eax > 0x0) {
                            asm { fstp       st1 };
                            while (true) {
                                    ecx = *(esi * 0x8 + 0x4f6b98);
                                    asm { fmul       qword [edi] };
                                    asm { fild       qword [esp+0x20+var_8] };
                                    asm { fdivp      st1 };
                                    asm { fld        qword [qword_value_4608083138725491507] };
                                    sub_47b370();
                                    asm { fmul       qword [qword_value_4647503709213818880] };
                                    esi = esi + 0x1;
                                    edi = edi + 0x8;
                                    asm { fadd       qword [edi-8] };
                                    asm { fstp       qword [edi-8] };
                                    if (esi >= *(ebx[0x2] + 0x2404)) {
                                            break;
                                    }
                                    asm { fld        qword [qword_value_4636737291354636288] };
                            }
                            asm { fldz };
                            asm { fld        qword [qword_value_4636737291354636288] };
                    }
                    eax = *(ebx[0x2] + 0x2404);
                    edi = var_10 + 0xa8;
                    var_10 = edi;
            } while (&decomp_var_m1 < eax);
    }
    edx = ebx[0x2];
    edx = edx[0x901];
    edi = 0x0;
    var_10 = 0x0;
    if (edx > 0x0) {
            ebp = 0xb82dc0;
            do {
                    esi = 0x0;
                    asm { fld        st1 };
                    if (edx >= 0x4) {
                            ecx = (edx - 0x4 >> 0x2) + 0x1;
                            eax = ebp;
                            esi = ecx * 0x4;
                            do {
                                    asm { fadd       qword [eax-8] };
                                    eax = eax + 0x20;
                                    ecx = ecx - 0x1;
                                    bool_19 = ecx != 0x0;
                                    asm { fadd       qword [eax-0x20] };
                                    asm { fadd       qword [eax-0x18] };
                                    asm { fadd       qword [eax-0x10] };
                            } while (bool_19);
                    }
                    if (esi < edx) {
                            ecx = (edi + esi) * 0x8 + 0xb82db8;
                            eax = edx - esi;
                            do {
                                    asm { fadd       qword [ecx] };
                                    ecx = ecx + 0x8;
                                    eax = eax - 0x1;
                            } while (eax != 0x0);
                    }
                    ecx = 0x0;
                    if (edx > 0x0) {
                            asm { fld        st2 };
                            asm { fucomp     st1 };
                            asm { fnstsw     ax };
                            if (PARITY(HIBYTE(eax) & 0x44)) {
                                    eax = edi + ecx;
                                    asm { fld        qword [dword_633f14+5566116+eax*8] };
                                    asm { fmul       st2 };
                                    asm { fdiv       st1 };
                                    asm { fstp       qword [dword_633f14+5566116+eax*8] };
                            }
                            eax = ebx[0x2];
                            ecx = ecx + 0x1;
                            if (ecx < eax[0x901]) {
                                    continue;
                            }
                            break;
                    }
                    eax = var_10;
                    asm { fstp       st0 };
                    edx = *(ebx[0x2] + 0x2404);
                    eax = eax + 0x1;
                    ebp = &arg_a0;
                    edi = edi + 0x15;
                    var_10 = eax;
            } while (eax < edx);
    }
    asm { fstp       st0 };
    asm { fstp       st0 };
    &var_10 = decomp_var_18;
    return eax;
}
