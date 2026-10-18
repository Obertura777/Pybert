// sub_4325a0 @ 0x4325a0
// hopper name: sub_4325a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4325a0() {
    var_C = *0x0;
    decomp_var_88 = ebx;
    decomp_var_8c = ebp;
    decomp_var_90 = esi;
    decomp_var_94 = edi;
    esp = esp - 0x98;
    decomp_var_98 = *dword_4c8db8 ^ &decomp_var_94;
    *0x0 = &var_C;
    edi = ecx;
    var_81 = 0x0;
    var_7C = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    ebx = arg_0;
    eax = *(ebx * 0x4 + 0xb9fdd8);
    ecx = edi[0x2];
    edx = ecx[0x2424] & 0xff;
    var_82 = 0x0;
    if (eax >= 0x0) {
            ebp = ebx * 0x15;
            var_74 = ebp;
            if (*((eax + ebp) * 0x4 + 0xba2888) == 0x0) {
                    ecx = ecx[0x901];
                    if (ecx > 0x0) {
                            esi = eax * 0x4 + 0xba2888;
                            do {
                                    if (*esi == 0x1) {
                                            var_82 = 0x1;
                                    }
                                    esi = esi + 0x54;
                            } while (&var_4 != 0x0);
                            ebp = var_74;
                    }
                    esi = edx * 0x15;
                    if (*((esi + ebx) * 0x4 + 0x6340c0) <= 0x3) {
                            if (*(int8_t *)byte_baed68 != 0x1) {
                                    if (var_82 == 0x1) {
                                            if (*(int8_t *)byte_baed68 == 0x1) {
                                                    if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                            if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                                    if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                                            if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                                                    esi = esi + eax;
                                                                                    if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                                                            asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                                                            eax = eax * 0x15;
                                                                                            asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                                                            eax = eax + edx;
                                                                                            ecx = eax * 0x8 + 0xb81228;
                                                                                            asm { fdivr      qword [ecx] };
                                                                                            asm { fcomp      qword [aWeNeedToElimin+48] };
                                                                                            asm { fnstsw     ax };
                                                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                    asm { fld        qword [qword_value_4617315517961601024] };
                                                                                                    asm { fcom       qword [ecx] };
                                                                                                    asm { fnstsw     ax };
                                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                            asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                                                            asm { fnstsw     ax };
                                                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                                    ebx = var_81;
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = ebx;
                                                                                                                    *0x0 = var_C;
                                                                                                            }
                                                                                                            else {
                                                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                                                    sub_465ff0(eax);
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                                                    sub_465ff0(eax);
                                                                                                                    sub_465fa0();
                                                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                                                    sub_465ff0(eax);
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465f30(&var_80);
                                                                                                                    sub_465ff0(&var_2C);
                                                                                                                    sub_465fa0();
                                                                                                                    eax = sub_465f60(&var_6C);
                                                                                                                    esp = esp - 0x64;
                                                                                                                    eax = sub_465f60(&var_5C);
                                                                                                                    sub_431940();
                                                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    sub_465fa0();
                                                                                                                    eax = 0x1;
                                                                                                                    *0x0 = var_C;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            asm { fstp       st0 };
                                                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                                                            eax = sub_466f80(&var_2C, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                                                            eax = sub_466f80(&var_1C, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465f30(&var_80);
                                                                                                            sub_465ff0(&var_2C);
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_465f60(&var_6C);
                                                                                                            esp = esp - 0x64;
                                                                                                            eax = sub_465f60(&var_5C);
                                                                                                            sub_431940();
                                                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0x1;
                                                                                                            *0x0 = var_C;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ebx = var_81;
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = ebx;
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = var_81;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = ebx;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = var_81;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = var_81;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                    eax = sub_466f80(&var_2C, eax);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                    eax = sub_466f80(&var_1C, eax);
                                                                    sub_465ff0(eax);
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465f30(&var_80);
                                                                    sub_465ff0(&var_2C);
                                                                    sub_465fa0();
                                                                    eax = sub_465f60(&var_6C);
                                                                    esp = esp - 0x64;
                                                                    eax = sub_465f60(&var_5C);
                                                                    sub_431940();
                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = 0x1;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                                    if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                                            esi = esi + eax;
                                                                            if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                                                    asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                                                    eax = eax * 0x15;
                                                                                    asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                                                    eax = eax + edx;
                                                                                    ecx = eax * 0x8 + 0xb81228;
                                                                                    asm { fdivr      qword [ecx] };
                                                                                    asm { fcomp      qword [aWeNeedToElimin+48] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            asm { fld        qword [qword_value_4617315517961601024] };
                                                                                            asm { fcom       qword [ecx] };
                                                                                            asm { fnstsw     ax };
                                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                    asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                                                    asm { fnstsw     ax };
                                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                            ebx = var_81;
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = ebx;
                                                                                                            *0x0 = var_C;
                                                                                                    }
                                                                                                    else {
                                                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                                                            eax = sub_466f80(&var_2C, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                                                            eax = sub_466f80(&var_1C, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465f30(&var_80);
                                                                                                            sub_465ff0(&var_2C);
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_465f60(&var_6C);
                                                                                                            esp = esp - 0x64;
                                                                                                            eax = sub_465f60(&var_5C);
                                                                                                            sub_431940();
                                                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0x1;
                                                                                                            *0x0 = var_C;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fstp       st0 };
                                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465f30(&var_80);
                                                                                                    sub_465ff0(&var_2C);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_465f60(&var_6C);
                                                                                                    esp = esp - 0x64;
                                                                                                    eax = sub_465f60(&var_5C);
                                                                                                    sub_431940();
                                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0x1;
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = var_81;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = ebx;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = var_81;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = var_81;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = var_81;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                            if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                                    esi = esi + eax;
                                                                    if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                                            asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                                            eax = eax * 0x15;
                                                                            asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                                            eax = eax + edx;
                                                                            ecx = eax * 0x8 + 0xb81228;
                                                                            asm { fdivr      qword [ecx] };
                                                                            asm { fcomp      qword [aWeNeedToElimin+48] };
                                                                            asm { fnstsw     ax };
                                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                                    asm { fld        qword [qword_value_4617315517961601024] };
                                                                                    asm { fcom       qword [ecx] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                                            asm { fnstsw     ax };
                                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                    ebx = var_81;
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = ebx;
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                            else {
                                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465f30(&var_80);
                                                                                                    sub_465ff0(&var_2C);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_465f60(&var_6C);
                                                                                                    esp = esp - 0x64;
                                                                                                    eax = sub_465f60(&var_5C);
                                                                                                    sub_431940();
                                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0x1;
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fstp       st0 };
                                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                                            eax = sub_466f80(&var_2C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                                            eax = sub_466f80(&var_1C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465f30(&var_80);
                                                                                            sub_465ff0(&var_2C);
                                                                                            sub_465fa0();
                                                                                            eax = sub_465f60(&var_6C);
                                                                                            esp = esp - 0x64;
                                                                                            eax = sub_465f60(&var_5C);
                                                                                            sub_431940();
                                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0x1;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = var_81;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = var_81;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = var_81;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            ebx = var_81;
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = ebx;
                                                            *0x0 = var_C;
                                                    }
                                            }
                                    }
                                    else {
                                            if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                    if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                            esi = esi + eax;
                                                            if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                                    asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                                    eax = eax * 0x15;
                                                                    asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                                    eax = eax + edx;
                                                                    ecx = eax * 0x8 + 0xb81228;
                                                                    asm { fdivr      qword [ecx] };
                                                                    asm { fcomp      qword [aWeNeedToElimin+48] };
                                                                    asm { fnstsw     ax };
                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                            asm { fld        qword [qword_value_4617315517961601024] };
                                                                            asm { fcom       qword [ecx] };
                                                                            asm { fnstsw     ax };
                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                    asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            ebx = var_81;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = ebx;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                                    else {
                                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                                            eax = sub_466f80(&var_2C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                                            eax = sub_466f80(&var_1C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465f30(&var_80);
                                                                                            sub_465ff0(&var_2C);
                                                                                            sub_465fa0();
                                                                                            eax = sub_465f60(&var_6C);
                                                                                            esp = esp - 0x64;
                                                                                            eax = sub_465f60(&var_5C);
                                                                                            sub_431940();
                                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0x1;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fstp       st0 };
                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465f30(&var_80);
                                                                                    sub_465ff0(&var_2C);
                                                                                    sub_465fa0();
                                                                                    eax = sub_465f60(&var_6C);
                                                                                    esp = esp - 0x64;
                                                                                    eax = sub_465f60(&var_5C);
                                                                                    sub_431940();
                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0x1;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = var_81;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = var_81;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            ebx = var_81;
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = ebx;
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    ebx = var_81;
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = ebx;
                                                    *0x0 = var_C;
                                            }
                                    }
                            }
                            else {
                                    var_80 = ebx & 0xff | 0x4100;
                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                    eax = sub_466540(&var_1C, &var_80);
                                    eax = sub_466f80(&var_2C, eax);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = sub_466ed0(&var_1C, &var_78);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    eax = sub_466330(&var_2C, &var_4C);
                                    eax = sub_466f80(&var_1C, eax);
                                    sub_465ff0(eax);
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465f30(&var_80);
                                    sub_465ff0(&var_2C);
                                    sub_465fa0();
                                    eax = sub_465f60(&var_6C);
                                    esp = esp - 0x64;
                                    eax = sub_465f60(&var_5C);
                                    sub_431940();
                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    sub_465fa0();
                                    eax = 0x1;
                                    *0x0 = var_C;
                            }
                    }
                    else {
                            if (var_82 == 0x1) {
                                    if (*(int8_t *)byte_baed68 == 0x1) {
                                            if (*(eax * 0x8 + 0x4d5480) == 0x1) {
                                                    if (*(eax * 0x8 + 0x4d5484) != 0x0) {
                                                            if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                                    if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                                            esi = esi + eax;
                                                                            if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                                                    asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                                                    eax = eax * 0x15;
                                                                                    asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                                                    eax = eax + edx;
                                                                                    ecx = eax * 0x8 + 0xb81228;
                                                                                    asm { fdivr      qword [ecx] };
                                                                                    asm { fcomp      qword [aWeNeedToElimin+48] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            asm { fld        qword [qword_value_4617315517961601024] };
                                                                                            asm { fcom       qword [ecx] };
                                                                                            asm { fnstsw     ax };
                                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                    asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                                                    asm { fnstsw     ax };
                                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                            ebx = var_81;
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = ebx;
                                                                                                            *0x0 = var_C;
                                                                                                    }
                                                                                                    else {
                                                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                                                            eax = sub_466f80(&var_2C, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                                                            eax = sub_466f80(&var_1C, eax);
                                                                                                            sub_465ff0(eax);
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465f30(&var_80);
                                                                                                            sub_465ff0(&var_2C);
                                                                                                            sub_465fa0();
                                                                                                            eax = sub_465f60(&var_6C);
                                                                                                            esp = esp - 0x64;
                                                                                                            eax = sub_465f60(&var_5C);
                                                                                                            sub_431940();
                                                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            sub_465fa0();
                                                                                                            eax = 0x1;
                                                                                                            *0x0 = var_C;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    asm { fstp       st0 };
                                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465f30(&var_80);
                                                                                                    sub_465ff0(&var_2C);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_465f60(&var_6C);
                                                                                                    esp = esp - 0x64;
                                                                                                    eax = sub_465f60(&var_5C);
                                                                                                    sub_431940();
                                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0x1;
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ebx = var_81;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = ebx;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = var_81;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = var_81;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = var_81;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            var_80 = ebx & 0xff | 0x4100;
                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                            eax = sub_466540(&var_1C, &var_80);
                                                            eax = sub_466f80(&var_2C, eax);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            eax = sub_466330(&var_2C, &var_4C);
                                                            eax = sub_466f80(&var_1C, eax);
                                                            sub_465ff0(eax);
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465f30(&var_80);
                                                            sub_465ff0(&var_2C);
                                                            sub_465fa0();
                                                            eax = sub_465f60(&var_6C);
                                                            esp = esp - 0x64;
                                                            eax = sub_465f60(&var_5C);
                                                            sub_431940();
                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = 0x1;
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                            if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                                    esi = esi + eax;
                                                                    if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                                            asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                                            eax = eax * 0x15;
                                                                            asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                                            eax = eax + edx;
                                                                            ecx = eax * 0x8 + 0xb81228;
                                                                            asm { fdivr      qword [ecx] };
                                                                            asm { fcomp      qword [aWeNeedToElimin+48] };
                                                                            asm { fnstsw     ax };
                                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                                    asm { fld        qword [qword_value_4617315517961601024] };
                                                                                    asm { fcom       qword [ecx] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                                            asm { fnstsw     ax };
                                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                                    ebx = var_81;
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = ebx;
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                            else {
                                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                                    sub_465ff0(eax);
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465f30(&var_80);
                                                                                                    sub_465ff0(&var_2C);
                                                                                                    sub_465fa0();
                                                                                                    eax = sub_465f60(&var_6C);
                                                                                                    esp = esp - 0x64;
                                                                                                    eax = sub_465f60(&var_5C);
                                                                                                    sub_431940();
                                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    sub_465fa0();
                                                                                                    eax = 0x1;
                                                                                                    *0x0 = var_C;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            asm { fstp       st0 };
                                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                                            eax = sub_466f80(&var_2C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                                            eax = sub_466f80(&var_1C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465f30(&var_80);
                                                                                            sub_465ff0(&var_2C);
                                                                                            sub_465fa0();
                                                                                            eax = sub_465f60(&var_6C);
                                                                                            esp = esp - 0x64;
                                                                                            eax = sub_465f60(&var_5C);
                                                                                            sub_431940();
                                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0x1;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ebx = var_81;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = var_81;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = var_81;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            ebx = var_81;
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = ebx;
                                                            *0x0 = var_C;
                                                    }
                                            }
                                    }
                                    else {
                                            if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                                    if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                            esi = esi + eax;
                                                            if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                                    asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                                    eax = eax * 0x15;
                                                                    asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                                    eax = eax + edx;
                                                                    ecx = eax * 0x8 + 0xb81228;
                                                                    asm { fdivr      qword [ecx] };
                                                                    asm { fcomp      qword [aWeNeedToElimin+48] };
                                                                    asm { fnstsw     ax };
                                                                    if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                            asm { fld        qword [qword_value_4617315517961601024] };
                                                                            asm { fcom       qword [ecx] };
                                                                            asm { fnstsw     ax };
                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                    asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                                    asm { fnstsw     ax };
                                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                            ebx = var_81;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = ebx;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                                    else {
                                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                                            eax = sub_466f80(&var_2C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                                            eax = sub_466f80(&var_1C, eax);
                                                                                            sub_465ff0(eax);
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465f30(&var_80);
                                                                                            sub_465ff0(&var_2C);
                                                                                            sub_465fa0();
                                                                                            eax = sub_465f60(&var_6C);
                                                                                            esp = esp - 0x64;
                                                                                            eax = sub_465f60(&var_5C);
                                                                                            sub_431940();
                                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            sub_465fa0();
                                                                                            eax = 0x1;
                                                                                            *0x0 = var_C;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    asm { fstp       st0 };
                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465f30(&var_80);
                                                                                    sub_465ff0(&var_2C);
                                                                                    sub_465fa0();
                                                                                    eax = sub_465f60(&var_6C);
                                                                                    esp = esp - 0x64;
                                                                                    eax = sub_465f60(&var_5C);
                                                                                    sub_431940();
                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0x1;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ebx = var_81;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = ebx;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = var_81;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            ebx = var_81;
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = ebx;
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    ebx = var_81;
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = ebx;
                                                    *0x0 = var_C;
                                            }
                                    }
                            }
                            else {
                                    if (*(eax * 0x8 + 0x4cf568) == 0x1) {
                                            if (*(eax * 0x8 + 0x4cf56c) == 0x0) {
                                                    esi = esi + eax;
                                                    if (*(esi * 0x4 + 0x6340c0) <= 0x3) {
                                                            asm { fld        qword [dword_633f14+5559060+esi*8] };
                                                            eax = eax * 0x15;
                                                            asm { fadd       qword [qword_value_4618441417868443648+8] };
                                                            eax = eax + edx;
                                                            ecx = eax * 0x8 + 0xb81228;
                                                            asm { fdivr      qword [ecx] };
                                                            asm { fcomp      qword [aWeNeedToElimin+48] };
                                                            asm { fnstsw     ax };
                                                            if (!PARITY(HIBYTE(eax) & 0x5)) {
                                                                    asm { fld        qword [qword_value_4617315517961601024] };
                                                                    asm { fcom       qword [ecx] };
                                                                    asm { fnstsw     ax };
                                                                    if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                            asm { fcomp      qword [dword_633f14+5559060+esi*8] };
                                                                            asm { fnstsw     ax };
                                                                            if (PARITY(HIBYTE(eax) & 0x5)) {
                                                                                    ebx = var_81;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = ebx;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                            else {
                                                                                    var_80 = ebx & 0xff | 0x4100;
                                                                                    var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                                    eax = sub_466540(&var_1C, &var_80);
                                                                                    eax = sub_466f80(&var_2C, eax);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = sub_466ed0(&var_1C, &var_78);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    eax = sub_466330(&var_2C, &var_4C);
                                                                                    eax = sub_466f80(&var_1C, eax);
                                                                                    sub_465ff0(eax);
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465f30(&var_80);
                                                                                    sub_465ff0(&var_2C);
                                                                                    sub_465fa0();
                                                                                    eax = sub_465f60(&var_6C);
                                                                                    esp = esp - 0x64;
                                                                                    eax = sub_465f60(&var_5C);
                                                                                    sub_431940();
                                                                                    *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    sub_465fa0();
                                                                                    eax = 0x1;
                                                                                    *0x0 = var_C;
                                                                            }
                                                                    }
                                                                    else {
                                                                            asm { fstp       st0 };
                                                                            var_80 = ebx & 0xff | 0x4100;
                                                                            var_78 = *(int8_t *)(ebx * 0x4 + 0xb9fdd8) & 0xff | 0x4100;
                                                                            eax = sub_466540(&var_1C, &var_80);
                                                                            eax = sub_466f80(&var_2C, eax);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = sub_466ed0(&var_1C, &var_78);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            eax = sub_466330(&var_2C, &var_4C);
                                                                            eax = sub_466f80(&var_1C, eax);
                                                                            sub_465ff0(eax);
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465f30(&var_80);
                                                                            sub_465ff0(&var_2C);
                                                                            sub_465fa0();
                                                                            eax = sub_465f60(&var_6C);
                                                                            esp = esp - 0x64;
                                                                            eax = sub_465f60(&var_5C);
                                                                            sub_431940();
                                                                            *((*(ebx * 0x4 + 0xb9fdd8) + ebp) * 0x4 + 0xba2888) = 0xfffffffc;
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            sub_465fa0();
                                                                            eax = 0x1;
                                                                            *0x0 = var_C;
                                                                    }
                                                            }
                                                            else {
                                                                    ebx = var_81;
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    sub_465fa0();
                                                                    eax = ebx;
                                                                    *0x0 = var_C;
                                                            }
                                                    }
                                                    else {
                                                            ebx = var_81;
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            sub_465fa0();
                                                            eax = ebx;
                                                            *0x0 = var_C;
                                                    }
                                            }
                                            else {
                                                    ebx = var_81;
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    sub_465fa0();
                                                    eax = ebx;
                                                    *0x0 = var_C;
                                            }
                                    }
                                    else {
                                            ebx = var_81;
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            sub_465fa0();
                                            eax = ebx;
                                            *0x0 = var_C;
                                    }
                            }
                    }
            }
            else {
                    ebx = var_81;
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = ebx;
                    *0x0 = var_C;
            }
    }
    else {
            ebx = var_81;
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            sub_465fa0();
            eax = ebx;
            *0x0 = var_C;
    }
    return eax;
}
