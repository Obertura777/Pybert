// sub_43ee00 @ 0x43ee00
// hopper name: sub_43ee00
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5603afdb33265f2ea0acc9a81cbc14c61d166c3a97fb9b974c9d4823276f52ec
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_43ee00() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_1ac = ebx;
    decomp_var_1b0 = ebp;
    decomp_var_1b4 = esi;
    decomp_var_1b8 = edi;
    esp = esp - 0x1bc;
    var_1BC = *dword_4c8db8 ^ &decomp_var_1b8;
    *0x0 = &var_C;
    edi = ecx;
    var_188 = edi;
    esi = 0x0;
    eax = sub_410370();
    var_190 = eax;
    eax[0x39] = 0x1;
    var_190[0x1] = var_190;
    *var_190 = var_190;
    var_190[0x2] = var_190;
    eax = sub_410370();
    var_174 = eax;
    eax[0x39] = 0x1;
    var_174[0x1] = var_174;
    *var_174 = var_174;
    var_174[0x2] = var_174;
    asm { fldz };
    eax = var_190;
    asm { fst        qword [esp+0x1bc+var_118] };
    ecx = eax[0x1];
    asm { fstp       qword [esp+0x1bc+var_110] };
    esp = esp - 0x4;
    sub_410d30(ecx);
    var_190[0x1] = var_190;
    *var_190 = var_190;
    var_190[0x2] = var_190;
    eax = edi[0x2];
    if (eax[0x900] <= esi) goto loc_43f00f;
    goto loc_43eefc;

loc_43f00f:
    eax = var_188[0x2];
    ebx = 0x0;
    var_164 = 0x0;
    if (eax[0x900] <= 0x0) goto loc_440162;
    goto loc_43f028;

loc_43eefc:
    esi = 0x0;
    var_1A8 = 0x0;
    goto loc_43ef00;

loc_440162:
    sub_41aa20(&var_F0, &var_178, *var_174, &var_178, var_174);
    sub_47c8f9();
    sub_41aa20(&var_F0, &var_194, *var_190, &var_194, var_190);
    eax = sub_47c8f9();
    *0x0 = var_C;
    &var_1A8 = decomp_var_1b0;
    return eax;

loc_43f028:
    goto loc_43f030;

loc_43ef00:
    ebx = eax + var_1A8 + 0x8;
    ebp = ebx;
    edi = *ebx[0x1];
    var_150 = ebp;
    var_14C = edi;
    &var_1BC = &var_1BC;
    goto loc_43ef20;

loc_43f030:
    ecx = eax + (ebx + ebx * 0x8) * 0x4 + 0x8;
    esi = ecx;
    edi = *ecx[0x1];
    var_D4 = ecx;
    var_150 = esi;
    var_14C = edi;
    goto loc_43f050;

loc_43ef20:
    var_F4 = ebx[0x1];
    if (ebp == 0x0 || ebp != ebx) {
            sub_47a948();
    }
    if (edi != var_F4) {
            if (ebp == 0x0) {
                    sub_47a948();
            }
            if (edi == ret_addr) {
                    sub_47a948();
            }
            eax = sub_422460(&var_194);
            eax = sub_4308b0(&var_98, &var_E8);
            eax = sub_41aa20(&var_F0, &var_E0, *var_DC, &var_E0, var_DC);
            sub_47c8f9();
            esp = (esp - 0x24) + 0x4;
            sub_401590();
            edi = var_14C;
            ebp = var_150;
            continue;
    }
    break;

loc_43f050:
    ebp = ecx[0x1];
    if (esi == 0x0 || esi != ecx) {
            sub_47a948();
    }
    if (edi == ebp) goto .l113;
    goto loc_43f068;
    eax = var_188[0x2];
    var_1A8 = var_1A8 + 0x24;
    esi = esi + 0x1;
    if (esi < eax[0x900]) {
            continue;
    }
    break;

.l113:
    break;

loc_43f068:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x6];
    asm { fld1 };
    ebp = var_164;
    asm { fst        qword [esp+0x1bc+var_118] };
    var_15C = eax;
    asm { fstp       qword [esp+0x1bc+var_110] };
    eax = var_190;
    edi = eax[0x1];
    ebx = 0x0;
    var_160 = ebp;
    var_120 = 0x0;
    esi = edi;
    if (edi[0x39] == 0x0) {
            do {
                    sub_410d30(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    bool_17 = true;
                    bool_16 = true;
                    edi = esi;
            } while (esi[0x39] == 0x0);
            eax = var_190;
    }
    eax[0x1] = eax;
    *var_190 = var_190;
    var_190[0x2] = var_190;
    var_148 = ebp;
    var_140 = var_120;
    eax = sub_4194b0(&var_34, &var_148);
    var_140 = var_120;
    esp = esp - 0x14;
    sub_433ae0(&var_160);
    sub_4194b0(decomp_var_1c4, decomp_var_1c0);
    goto loc_43f180;
    eax = var_188[0x2];
    ebx = ebx + 0x1;
    var_164 = ebx;
    if (ebx < eax[0x900]) {
            continue;
    }
    break;

loc_43f180:
    esi = *var_190;
    ebx = ebx + 0x1;
    edi = &var_194;
    var_179 = 0x0;
    var_1A0 = ebx;
    var_19C = edi;
    var_198 = esi;
    goto loc_43f1a0;

loc_43f1a0:
    ebp = var_190;
    if (edi == 0x0 || edi != &var_194) {
            sub_47a948();
    }
    if (esi == ebp) goto .l83;
    goto loc_43f1bd;

.l83:
    break;

loc_43f1bd:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != ebx - 0x1) {
            sub_40f7f0();
            esi = var_198;
            edi = var_19C;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            bool_193 = esi != edi[0x1];
            bool_185 = esi >= edi[0x1];
            if (!bool_193) {
                    sub_47a948();
            }
    }
    eax = esi + 0x14;
    esp = esp - 0x4;
    eax = sub_4075b0(eax, var_1BC);
    asm { fld        dword [dword_value_1088421888] };
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    edi = eax;
    var_158 = edi;
    var_120 = ebx;
    eax = ebx;
    if (!bool_185) {
            eax = -eax;
    }
    asm { fld1 };
    asm { fst        dword [esp+0x1bc+var_1A8] };
    while (true) {
            bool_225 = (eax & 0x1) == 0x0;
            asm { fld        dword [esp+0x1bc+var_1A4] };
            if (!bool_225) {
                    asm { fld        dword [esp+0x1bc+var_1A8] };
                    asm { fmul       st1 };
                    asm { fstp       dword [esp+0x1bc+var_1A8] };
            }
            eax = eax >> 0x1;
            bool_182 = eax >= 0x0;
            if (eax == 0x0) {
                    break;
            }
            asm { fmul       st0, st0 };
            asm { fstp       dword [esp+0x1bc+var_1A4] };
    }
    asm { fstp       st0 };
    asm { fld        dword [esp+0x1bc+var_1A8] };
    asm { fld1 };
    bool_186 = asm { fld1 };
    if (!bool_182) {
            asm { fld        st0 };
            asm { fdivrp     st2 };
    }
    asm { fxch       st0, st1 };
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    eax = ebx;
    asm { fld        qword [qword_value_4609434218613702656] };
    asm { fld        st0 };
    if (!bool_186) {
            eax = -eax;
    }
    asm { fld        st2 };
    while (true) {
            if ((eax & 0x1) != 0x0) {
                    asm { fmul       st1 };
            }
            eax = eax >> 0x1;
            bool_195 = eax >= 0x0;
            if (eax == 0x0) {
                    break;
            }
            asm { fld        st1 };
            asm { fmulp      st2 };
    }
    asm { fstp       st1 };
    bool_191 = asm { fstp       st1 };
    if (!bool_195) {
            asm { fdivr      st2 };
    }
    asm { fld        qword [qword_value_4629137466983448576] };
    asm { fmul       st1, st0 };
    eax = ebx;
    asm { fld        st3 };
    asm { fdivrp     st2 };
    asm { fld        dword [esp+0x1bc+var_1A4] };
    asm { fdivr      st4 };
    asm { faddp      st2 };
    asm { fld        st3 };
    asm { fdivrp     st2 };
    asm { fxch       st0, st1 };
    asm { fstp       qword [esp+0x1bc+var_118] };
    asm { fld        dword [dword_value_1090519040] };
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    if (!bool_191) {
            eax = -eax;
    }
    asm { fxch       st0, st3 };
    asm { fstp       dword [esp+0x1bc+var_1A8] };
    while (true) {
            bool_201 = (eax & 0x1) == 0x0;
            asm { fld        dword [esp+0x1bc+var_1A4] };
            if (!bool_201) {
                    asm { fld        dword [esp+0x1bc+var_1A8] };
                    asm { fmul       st1 };
                    asm { fstp       dword [esp+0x1bc+var_1A8] };
            }
            eax = eax >> 0x1;
            bool_184 = eax >= 0x0;
            if (eax == 0x0) {
                    break;
            }
            asm { fmul       st0, st0 };
            asm { fstp       dword [esp+0x1bc+var_1A4] };
    }
    asm { fstp       st0 };
    asm { fld        dword [esp+0x1bc+var_1A8] };
    bool_180 = asm { fld        dword [esp+0x1bc+var_1A8] };
    if (!bool_184) {
            asm { fdivr      st2 };
    }
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    eax = ebx;
    if (!bool_180) {
            eax = -eax;
    }
    asm { fld        st1 };
    while (true) {
            if ((eax & 0x1) != 0x0) {
                    asm { fmul       st1 };
            }
            eax = eax >> 0x1;
            bool_194 = eax >= 0x0;
            if (eax == 0x0) {
                    break;
            }
            asm { fld        st1 };
            asm { fmulp      st2 };
    }
    asm { fstp       st1 };
    if (!bool_194) {
            asm { fdivr      st1 };
    }
    asm { fmulp      st2 };
    esi = *edi[0x1];
    var_184 = edi;
    asm { fld        st0 };
    var_180 = esi;
    asm { fdivrp     st2 };
    asm { fld        dword [esp+0x1bc+var_1A4] };
    asm { fdivr      st1 };
    asm { faddp      st2 };
    asm { fdivrp     st1 };
    asm { fstp       qword [esp+0x1bc+var_110] };
    goto loc_43f340;
    if (var_179 == 0x1) {
            continue;
    }
    break;

loc_43f340:
    eax = var_158;
    ebp = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_203 = esi != edi[0x1];
            var_168 = esi[0x8];
            if (!bool_203) {
                    sub_47a948();
            }
            ebp = esi[0x3];
            var_16C = ebp;
            eax = sub_433ae0(&var_16C);
            edi = eax;
            var_80 = edi[0x1];
            esp = esp - 0x8;
            eax = sub_433ae0(&var_16C);
            edx = eax[0x1];
            ecx = edx[0x1];
            if (ecx[0x39] != 0x0) {
                    esi = eax[0x1];
                    var_A0 = eax;
                    if (edx != esi) {
                            ecx = edx[0x4];
                            bool_216 = ebx != ecx;
                            if (var_164 >= ecx) {
                                    if (!bool_216 && var_15C < edx[0xa]) {
                                            ebx = var_1A0;
                                            var_C0 = eax;
                                            eax = &var_C0;
                                    }
                                    else {
                                            ebx = var_1A0;
                                            eax = &var_A0;
                                    }
                            }
                            else {
                                    ebx = var_1A0;
                                    var_C0 = eax;
                                    eax = &var_C0;
                            }
                    }
                    else {
                            var_C0 = eax;
                            eax = &var_C0;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    bool_210 = true;
                    bool_209 = true;
                    if (esi == var_80) {
                            var_140 = var_120;
                            sub_433ae0(&var_16C);
                            sub_4194b0(decomp_var_1c4, decomp_var_1c0);
                            var_148 = ebp;
                            var_140 = var_120;
                            esp = esp - 0x14;
                            eax = sub_4194b0(&var_1C, &var_148);
                            var_179 = 0x1;
                    }
                    sub_40f400();
                    esi = var_180;
                    edi = var_184;
                    continue;
            }
            ebx = var_164;
            do {
                    esi = ecx[0x4];
                    bool_218 = esi != ebx;
                    if (esi < ebx) {
                            ecx = ecx[0x2];
                            if (ecx[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_218) {
                            edx = ecx;
                            ecx = *ecx;
                            if (ecx[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (ecx[0xa] < var_15C) {
                            ecx = ecx[0x2];
                    }
                    else {
                            edx = ecx;
                            ecx = *ecx;
                    }
            } while (ecx[0x39] == 0x0);
            ebx = var_1A0;
            esi = eax[0x1];
            var_A0 = eax;
            if (edx != esi) {
                    ecx = edx[0x4];
                    bool_216 = ebx != ecx;
                    if (var_164 >= ecx) {
                            if (!bool_216 && var_15C < edx[0xa]) {
                                    ebx = var_1A0;
                                    var_C0 = eax;
                                    eax = &var_C0;
                            }
                            else {
                                    ebx = var_1A0;
                                    eax = &var_A0;
                            }
                    }
                    else {
                            ebx = var_1A0;
                            var_C0 = eax;
                            eax = &var_C0;
                    }
            }
            else {
                    var_C0 = eax;
                    eax = &var_C0;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            bool_210 = true;
            bool_209 = true;
            if (esi == var_80) {
                    var_140 = var_120;
                    sub_433ae0(&var_16C);
                    sub_4194b0(decomp_var_1c4, decomp_var_1c0);
                    var_148 = ebp;
                    var_140 = var_120;
                    esp = esp - 0x14;
                    eax = sub_4194b0(&var_1C, &var_148);
                    var_179 = 0x1;
            }
            sub_40f400();
            esi = var_180;
            edi = var_184;
            continue;
    }
    break;
    if (*(int16_t *)word_4c6c08 != var_15C) {
            sub_401590();
            edi = var_14C;
            esi = var_150;
            ebx = var_164;
            ecx = var_D4;
            continue;
    }
    eax = var_174;
    edi = eax[0x1];
    esi = edi;
    if (edi[0x39] == 0x0) {
            do {
                    sub_410d30(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    edi = esi;
            } while (esi[0x39] == 0x0);
            eax = var_174;
    }
    eax[0x1] = eax;
    ebx = 0x0;
    *var_174 = var_174;
    var_174[0x2] = var_174;
    eax = var_1A0;
    var_1A4 = 0x0;
    if (eax < 0x0) goto loc_43f781;
    goto loc_43f580;
    sub_40f7f0();
    esi = var_198;
    edi = var_19C;
    continue;

loc_43f781:
    ebx = 0x0;
    var_1A4 = 0x0;
    var_1A8 = eax + 0x2;
    if (eax < 0xfffffffe) goto loc_43f9ca;
    goto loc_43f796;

loc_43f580:
    edi = *var_190;
    esi = &var_194;
    var_19C = esi;
    var_198 = edi;
    goto loc_43f592;

loc_43f9ca:
    ebx = 0x0;
    var_1A0 = 0x0;
    var_154 = eax + 0x3;
    if (eax < 0xfffffffd) goto loc_43fd8f;
    goto loc_43f9dd;

loc_43f796:
    esi = *var_174;
    edi = &var_178;
    var_19C = edi;
    var_198 = esi;
    goto loc_43f7a8;

loc_43f592:
    ebp = var_190;
    if (esi == 0x0 || esi != &var_194) {
            sub_47a948();
    }
    if (edi == ebp) goto .l89;
    goto loc_43f5af;

loc_43fd8f:
    ebx = 0x0;
    var_1A0 = 0x0;
    goto loc_43fd95;

loc_43f9dd:
    goto loc_43f9e0;

loc_43f7a8:
    ebp = var_174;
    if (edi == 0x0 || edi != &var_178) {
            sub_47a948();
    }
    if (esi == ebp) goto .l86;
    goto loc_43f7c5;

.l89:
    break;

loc_43f5af:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    if (edi[0x6] != ebx) {
            sub_40f7f0();
            edi = var_198;
            esi = var_19C;
            ebx = var_1A4;
            continue;
    }
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    var_120 = edi[0x6] + 0x1;
    if (edi == esi[0x1]) {
            sub_47a948();
    }
    eax = edi[0x4];
    edx = var_188[0x2];
    ebp = **(edx + (eax + eax * 0x8) * 0x4 + 0xc);
    eax = edx + (eax + eax * 0x8) * 0x4 + 0x8;
    esi = eax;
    var_1A8 = eax;
    var_100 = esi;
    var_FC = ebp;
    goto loc_43f617;

loc_43fd95:
    ebp = &var_194;
    edi = *var_190;
    var_19C = ebp;
    var_198 = edi;
    &var_1BC = &var_1BC;
    goto loc_43fdb0;

loc_43f9e0:
    ebp = &var_178;
    edi = *var_174;
    var_19C = ebp;
    var_198 = edi;
    goto loc_43f9f4;

.l86:
    break;

loc_43f7c5:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    var_120 = esi[0x6] + 0x1;
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != ebx) {
            sub_40f7f0();
            esi = var_198;
            edi = var_19C;
            ebx = var_1A4;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    eax = esi + 0x14;
    esp = esp - 0x4;
    eax = sub_4075b0(eax, var_1BC);
    esi = *eax[0x1];
    ebx = eax;
    var_158 = eax;
    var_184 = ebx;
    var_180 = esi;
    &var_1BC = &var_1BC;
    goto loc_43f840;
    eax = var_1A0;
    ebx = ebx + 0x1;
    var_1A4 = ebx;
    if (ebx <= eax) {
            continue;
    }
    break;

loc_43f617:
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (ebp == ebx) goto .l74;
    goto loc_43f62f;

loc_43fdb0:
    esi = var_190;
    if (ebp == 0x0 || ebp != &var_194) {
            sub_47a948();
    }
    if (edi == esi) goto .l80;
    goto loc_43fdcd;

loc_43f9f4:
    esi = var_174;
    if (ebp == 0x0 || ebp != &var_178) {
            sub_47a948();
    }
    if (edi == esi) goto .l77;
    goto loc_43fa11;
    ebx = ebx + 0x1;
    var_1A4 = ebx;
    if (ebx <= var_1A8) {
            continue;
    }
    break;

loc_43f840:
    edi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi != edi) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(var_188[0x2] + (eax + eax * 0x8) * 0x4 + 0x4) != 0x0) {
                    sub_40f400();
                    esi = var_180;
                    ebx = var_184;
                    eax = var_158;
                    continue;
            }
            ebp = var_174;
            var_88 = ebp;
            if (esi == ebx[0x1]) {
                    sub_47a948();
                    ebp = var_174;
            }
            eax = ret_addr;
            edx = ebp;
            if (eax[0x39] != 0x0) {
                    var_B0 = &var_178;
                    if (edx != ebp) {
                            eax = esi[0x3];
                            ecx = edx[0x4];
                            bool_96 = eax != ecx;
                            if (eax >= ecx) {
                                    if (!bool_96 && esi[0x8] < edx[0xa]) {
                                            var_C8 = &var_178;
                                            eax = &var_C8;
                                    }
                                    else {
                                            eax = &var_B0;
                                    }
                            }
                            else {
                                    var_C8 = &var_178;
                                    eax = &var_C8;
                            }
                    }
                    else {
                            var_C8 = &var_178;
                            eax = &var_C8;
                    }
                    ecx = *eax;
                    edi = eax[0x1];
                    if (ecx == 0x0 || ecx != &var_178) {
                            sub_47a948();
                    }
                    if (edi == var_88) {
                            bool_87 = true;
                            if (esi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            var_148 = esi[0x3];
                            var_140 = var_120;
                            esp = esp - 0x8;
                            eax = sub_4194b0(&var_58, &var_148);
                    }
                    sub_40f400();
                    esi = var_180;
                    ebx = var_184;
                    eax = var_158;
                    continue;
            }
            edi = esi[0x3];
            do {
                    ecx = eax[0x4];
                    bool_101 = ecx != edi;
                    if (ecx < edi) {
                            eax = eax[0x2];
                            if (eax[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_101) {
                            edx = eax;
                            eax = *eax;
                            if (eax[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (eax[0xa] < esi[0x8]) {
                            eax = eax[0x2];
                    }
                    else {
                            edx = eax;
                            eax = *eax;
                    }
            } while (eax[0x39] == 0x0);
            var_B0 = &var_178;
            if (edx != ebp) {
                    eax = esi[0x3];
                    ecx = edx[0x4];
                    bool_96 = eax != ecx;
                    if (eax >= ecx) {
                            if (!bool_96 && esi[0x8] < edx[0xa]) {
                                    var_C8 = &var_178;
                                    eax = &var_C8;
                            }
                            else {
                                    eax = &var_B0;
                            }
                    }
                    else {
                            var_C8 = &var_178;
                            eax = &var_C8;
                    }
            }
            else {
                    var_C8 = &var_178;
                    eax = &var_C8;
            }
            ecx = *eax;
            edi = eax[0x1];
            if (ecx == 0x0 || ecx != &var_178) {
                    sub_47a948();
            }
            if (edi == var_88) {
                    bool_87 = true;
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    var_148 = esi[0x3];
                    var_140 = var_120;
                    esp = esp - 0x8;
                    eax = sub_4194b0(&var_58, &var_148);
            }
            sub_40f400();
            esi = var_180;
            ebx = var_184;
            eax = var_158;
            continue;
    }
    break;

.l74:
    break;

loc_43f62f:
    if (esi == 0x0) {
            sub_47a948();
    }
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    ebx = &arg_4;
    if (*(int16_t *)word_4c6c08 == arg_4) {
            sub_401590();
            ebp = var_FC;
            esi = var_100;
            edi = var_198;
            eax = var_1A8;
            continue;
    }
    if (ebp == esi[0x1]) {
            sub_47a948();
    }
    if (edi == var_19C[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    ebp = sub_4075b0(ebx, var_1BC);
    esi = *ret_addr;
    edi = ebp;
    var_184 = edi;
    var_180 = esi;
    goto loc_43f696;

.l80:
    break;

loc_43fdcd:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (edi == ret_addr) {
            sub_47a948();
    }
    eax = edi[0x6];
    asm { fld        dword [dword_value_1088421888] };
    eax = eax + 0x1;
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    var_120 = eax;
    ecx = eax;
    if (!asm { fstp       dword [esp+0x1bc+var_1A4] }) {
            ecx = -ecx;
    }
    asm { fld1 };
    asm { fst        dword [esp+0x1bc+var_1A8] };
    while (true) {
            bool_150 = (ecx & 0x1) == 0x0;
            asm { fld        dword [esp+0x1bc+var_1A4] };
            if (!bool_150) {
                    asm { fld        dword [esp+0x1bc+var_1A8] };
                    asm { fmul       st1 };
                    asm { fstp       dword [esp+0x1bc+var_1A8] };
            }
            ecx = ecx >> 0x1;
            bool_148 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fmul       st0, st0 };
            asm { fstp       dword [esp+0x1bc+var_1A4] };
    }
    asm { fstp       st0 };
    asm { fld        dword [esp+0x1bc+var_1A8] };
    asm { fld1 };
    bool_139 = asm { fld1 };
    if (!bool_148) {
            asm { fld        st0 };
            asm { fdivrp     st2 };
    }
    asm { fxch       st0, st1 };
    asm { fstp       dword [esp+0x1bc+var_154] };
    ecx = eax;
    asm { fld        qword [qword_value_4609434218613702656] };
    asm { fld        st0 };
    if (!bool_139) {
            ecx = -ecx;
    }
    asm { fld        st2 };
    while (true) {
            if ((ecx & 0x1) != 0x0) {
                    asm { fmul       st1 };
            }
            ecx = ecx >> 0x1;
            bool_141 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fld        st1 };
            asm { fmulp      st2 };
    }
    asm { fstp       st1 };
    bool_144 = asm { fstp       st1 };
    if (!bool_141) {
            asm { fdivr      st2 };
    }
    asm { fld        qword [qword_value_4643985272004935680] };
    asm { fmul       st1, st0 };
    ecx = eax;
    asm { fld        st3 };
    asm { fdivrp     st2 };
    asm { fld        dword [esp+0x1bc+var_154] };
    asm { fldz };
    asm { fmul       st1, st0 };
    asm { fxch       st0, st3 };
    asm { faddp      st1 };
    asm { fdivr      st4 };
    asm { fstp       qword [esp+0x1bc+var_118] };
    asm { fld        dword [dword_value_1090519040] };
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    if (!bool_144) {
            ecx = -ecx;
    }
    asm { fxch       st0, st4 };
    asm { fstp       dword [esp+0x1bc+var_1A8] };
    while (true) {
            bool_175 = (ecx & 0x1) == 0x0;
            asm { fld        dword [esp+0x1bc+var_1A4] };
            if (!bool_175) {
                    asm { fld        dword [esp+0x1bc+var_1A8] };
                    asm { fmul       st1 };
                    asm { fstp       dword [esp+0x1bc+var_1A8] };
            }
            ecx = ecx >> 0x1;
            bool_137 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fmul       st0, st0 };
            asm { fstp       dword [esp+0x1bc+var_1A4] };
    }
    asm { fstp       st0 };
    asm { fld        dword [esp+0x1bc+var_1A8] };
    bool_143 = asm { fld        dword [esp+0x1bc+var_1A8] };
    if (!bool_137) {
            asm { fdivr      st3 };
    }
    asm { fstp       dword [esp+0x1bc+var_154] };
    ecx = eax;
    if (!bool_143) {
            ecx = -ecx;
    }
    asm { fld        st2 };
    while (true) {
            if ((ecx & 0x1) != 0x0) {
                    asm { fmul       st2 };
            }
            ecx = ecx >> 0x1;
            bool_136 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fld        st2 };
            asm { fmulp      st3 };
    }
    asm { fstp       st2 };
    if (!bool_136) {
            asm { fld        st2 };
            asm { fdivrp     st2 };
    }
    bool_146 = edi != ret_addr;
    asm { fxch       st0, st1 };
    asm { fmulp      st3 };
    asm { fld        st1 };
    asm { fdivrp     st3 };
    asm { fmul       dword [esp+0x1bc+var_154] };
    asm { faddp      st2 };
    asm { fdivrp     st1 };
    asm { fstp       qword [esp+0x1bc+var_110] };
    if (!bool_146) {
            sub_47a948();
    }
    if (edi[0x6] != ebx) {
            sub_40f7f0();
            edi = var_198;
            ebp = var_19C;
            ebx = var_1A0;
            continue;
    }
    if (edi == ret_addr) {
            sub_47a948();
            if (edi == ret_addr) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x14, var_1BC);
    esi = *eax[0x1];
    ebx = var_164;
    edi = eax;
    var_158 = eax;
    var_184 = edi;
    var_180 = esi;
    goto loc_43ff70;

.l77:
    break;

loc_43fa11:
    if (ebp == 0x0) {
            sub_47a948();
    }
    if (edi == ret_addr) {
            sub_47a948();
    }
    eax = edi[0x6];
    asm { fld        dword [dword_value_1088421888] };
    eax = eax + 0x1;
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    var_120 = eax;
    ecx = eax;
    if (!asm { fstp       dword [esp+0x1bc+var_1A4] }) {
            ecx = -ecx;
    }
    asm { fld1 };
    asm { fst        dword [esp+0x1bc+var_1A8] };
    while (true) {
            bool_63 = (ecx & 0x1) == 0x0;
            asm { fld        dword [esp+0x1bc+var_1A4] };
            if (!bool_63) {
                    asm { fld        dword [esp+0x1bc+var_1A8] };
                    asm { fmul       st1 };
                    asm { fstp       dword [esp+0x1bc+var_1A8] };
            }
            ecx = ecx >> 0x1;
            bool_31 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fmul       st0, st0 };
            asm { fstp       dword [esp+0x1bc+var_1A4] };
    }
    asm { fstp       st0 };
    asm { fld        dword [esp+0x1bc+var_1A8] };
    asm { fld1 };
    bool_26 = asm { fld1 };
    if (!bool_31) {
            asm { fld        st0 };
            asm { fdivrp     st2 };
    }
    asm { fxch       st0, st1 };
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    ecx = eax;
    asm { fld        qword [qword_value_4609434218613702656] };
    asm { fld        st0 };
    if (!bool_26) {
            ecx = -ecx;
    }
    asm { fld        st2 };
    while (true) {
            if ((ecx & 0x1) != 0x0) {
                    asm { fmul       st1 };
            }
            ecx = ecx >> 0x1;
            bool_33 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fld        st1 };
            asm { fmulp      st2 };
    }
    asm { fstp       st1 };
    bool_34 = asm { fstp       st1 };
    if (!bool_33) {
            asm { fdivr      st2 };
    }
    asm { fld        qword [qword_value_4643985272004935680] };
    asm { fmul       st1, st0 };
    ecx = eax;
    asm { fld        st3 };
    asm { fdivrp     st2 };
    asm { fld        dword [esp+0x1bc+var_1A4] };
    asm { fldz };
    asm { fmul       st1, st0 };
    asm { fxch       st0, st3 };
    asm { faddp      st1 };
    asm { fdivr      st4 };
    asm { fstp       qword [esp+0x1bc+var_118] };
    asm { fld        dword [dword_value_1090519040] };
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    if (!bool_34) {
            ecx = -ecx;
    }
    asm { fxch       st0, st4 };
    asm { fstp       dword [esp+0x1bc+var_1A8] };
    while (true) {
            bool_69 = (ecx & 0x1) == 0x0;
            asm { fld        dword [esp+0x1bc+var_1A4] };
            if (!bool_69) {
                    asm { fld        dword [esp+0x1bc+var_1A8] };
                    asm { fmul       st1 };
                    asm { fstp       dword [esp+0x1bc+var_1A8] };
            }
            ecx = ecx >> 0x1;
            bool_35 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fmul       st0, st0 };
            asm { fstp       dword [esp+0x1bc+var_1A4] };
    }
    asm { fstp       st0 };
    asm { fld        dword [esp+0x1bc+var_1A8] };
    bool_24 = asm { fld        dword [esp+0x1bc+var_1A8] };
    if (!bool_35) {
            asm { fdivr      st3 };
    }
    asm { fstp       dword [esp+0x1bc+var_1A4] };
    ecx = eax;
    if (!bool_24) {
            ecx = -ecx;
    }
    asm { fld        st2 };
    while (true) {
            if ((ecx & 0x1) != 0x0) {
                    asm { fmul       st2 };
            }
            ecx = ecx >> 0x1;
            bool_37 = ecx >= 0x0;
            if (ecx == 0x0) {
                    break;
            }
            asm { fld        st2 };
            asm { fmulp      st3 };
    }
    asm { fstp       st2 };
    if (!bool_37) {
            asm { fld        st2 };
            asm { fdivrp     st2 };
    }
    bool_28 = edi != ret_addr;
    asm { fxch       st0, st1 };
    asm { fmulp      st3 };
    asm { fld        st1 };
    asm { fdivrp     st3 };
    asm { fmul       dword [esp+0x1bc+var_1A4] };
    asm { faddp      st2 };
    asm { fdivrp     st1 };
    asm { fstp       qword [esp+0x1bc+var_110] };
    if (!bool_28) {
            sub_47a948();
    }
    if (edi[0x6] != ebx) {
            sub_40f7f0();
            edi = var_198;
            ebp = var_19C;
            ebx = var_1A0;
            continue;
    }
    if (edi == ret_addr) {
            sub_47a948();
            if (edi == ret_addr) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x14, var_1BC);
    esi = *eax[0x1];
    ebx = var_164;
    edi = eax;
    var_158 = eax;
    var_184 = edi;
    var_180 = esi;
    goto loc_43fbb0;
    eax = var_1A0;
    goto loc_43f9ca;
    sub_40f7f0();
    esi = var_198;
    edi = var_19C;
    ebx = var_1A4;
    continue;
    sub_40f7f0();
    edi = var_198;
    esi = var_19C;
    ebx = var_1A4;
    continue;

loc_43f696:
    ebx = ret_addr;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(var_188[0x2] + (eax + eax * 0x8) * 0x4 + 0x4) == 0x0) {
                    bool_124 = true;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    var_148 = esi[0x3];
                    var_140 = var_120;
                    esp = esp - 0x8;
                    eax = sub_4194b0(&var_40, &var_148);
            }
            sub_40f400();
            esi = var_180;
            edi = var_184;
            continue;
    }
    break;
    ebx = ebx + 0x1;
    var_1A0 = ebx;
    if (ebx <= 0xa) {
            continue;
    }
    break;

loc_43ff70:
    eax = var_158;
    ebp = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_158 = esi != edi[0x1];
            var_168 = esi[0x8];
            if (!bool_158) {
                    sub_47a948();
            }
            var_16C = esi[0x3];
            eax = sub_433ae0(&var_16C);
            edi = eax;
            esp = esp - 0x8;
            var_EC = edi[0x1];
            eax = sub_433ae0(&var_16C);
            edx = eax[0x1];
            ecx = edx[0x1];
            ebp = var_15C;
            if (ecx[0x39] == 0x0) {
                    esi = ecx[0x4];
                    bool_169 = esi != ebx;
                    if (esi >= ebx) {
                            if (!bool_169) {
                                    if (ecx[0xa] < ebp) {
                                            ecx = ecx[0x2];
                                    }
                                    else {
                                            edx = ecx;
                                            ecx = *ecx;
                                    }
                                    if (ecx[0x39] == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    edx = ecx;
                                    ecx = *ecx;
                                    if (ecx[0x39] == 0x0) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            ecx = ecx[0x2];
                            if (ecx[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
            }
            esi = eax[0x1];
            var_A8 = eax;
            if (edx != esi) {
                    ecx = edx[0x4];
                    bool_154 = ebx != ecx;
                    if (ebx >= ecx) {
                            if (!bool_154 && ebp < edx[0xa]) {
                                    var_F8 = eax;
                                    eax = &var_F8;
                            }
                            else {
                                    eax = &var_A8;
                            }
                    }
                    else {
                            var_F8 = eax;
                            eax = &var_F8;
                    }
            }
            else {
                    var_F8 = eax;
                    eax = &var_F8;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            bool_166 = true;
            bool_165 = true;
            if (esi == var_EC) {
                    var_140 = var_120;
                    sub_433ae0(&var_16C);
                    sub_4194b0(decomp_var_1c4, decomp_var_1c0);
                    var_148 = var_16C;
                    var_140 = var_120;
                    esp = esp - 0x14;
                    eax = sub_4194b0(&var_E8, &var_148);
            }
            sub_40f400();
            esi = var_180;
            edi = var_184;
            continue;
    }
    break;
    ebx = ebx + 0x1;
    var_1A0 = ebx;
    if (ebx <= var_154) {
            continue;
    }
    break;

loc_43fbb0:
    eax = var_158;
    ebp = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != ebp) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x3];
            if (*(int8_t *)(var_188[0x2] + (eax + eax * 0x8) * 0x4 + 0x4) != 0x1) {
                    sub_40f400();
                    esi = var_180;
                    edi = var_184;
                    continue;
            }
            bool_46 = esi != edi[0x1];
            var_168 = *(int16_t *)word_4c6c08;
            if (!bool_46) {
                    sub_47a948();
            }
            ebp = esi[0x3];
            var_16C = ebp;
            eax = sub_433ae0(&var_16C);
            edi = eax;
            esp = esp - 0x8;
            var_94 = edi[0x1];
            eax = sub_433ae0(&var_16C);
            edx = eax[0x1];
            ecx = edx[0x1];
            if (ecx[0x39] != 0x0) {
                    esi = eax[0x1];
                    var_B8 = eax;
                    if (edx != esi) {
                            ecx = edx[0x4];
                            bool_44 = ebx != ecx;
                            if (ebx >= ecx) {
                                    if (!bool_44 && var_15C < edx[0xa]) {
                                            var_D0 = eax;
                                            eax = &var_D0;
                                    }
                                    else {
                                            eax = &var_B8;
                                    }
                            }
                            else {
                                    var_D0 = eax;
                                    eax = &var_D0;
                            }
                    }
                    else {
                            var_D0 = eax;
                            eax = &var_D0;
                    }
                    ecx = *eax;
                    esi = eax[0x1];
                    if (ecx == 0x0 || ecx != edi) {
                            sub_47a948();
                    }
                    bool_54 = true;
                    bool_53 = true;
                    if (esi == var_94) {
                            var_140 = var_120;
                            sub_433ae0(&var_16C);
                            sub_4194b0(decomp_var_1c4, decomp_var_1c0);
                            var_148 = ebp;
                            var_140 = var_120;
                            esp = esp - 0x14;
                            eax = sub_4194b0(&var_70, &var_148);
                    }
                    sub_40f400();
                    esi = var_180;
                    edi = var_184;
                    continue;
            }
            &var_1BC = &var_1BC;
            do {
                    esi = ecx[0x4];
                    bool_57 = esi != ebx;
                    if (esi < ebx) {
                            ecx = ecx[0x2];
                            if (ecx[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (bool_57) {
                            edx = ecx;
                            ecx = *ecx;
                            if (ecx[0x39] == 0x0) {
                                    continue;
                            }
                            break;
                    }
                    if (ecx[0xa] < var_15C) {
                            ecx = ecx[0x2];
                    }
                    else {
                            edx = ecx;
                            ecx = *ecx;
                    }
            } while (ecx[0x39] == 0x0);
            esi = eax[0x1];
            var_B8 = eax;
            if (edx != esi) {
                    ecx = edx[0x4];
                    bool_44 = ebx != ecx;
                    if (ebx >= ecx) {
                            if (!bool_44 && var_15C < edx[0xa]) {
                                    var_D0 = eax;
                                    eax = &var_D0;
                            }
                            else {
                                    eax = &var_B8;
                            }
                    }
                    else {
                            var_D0 = eax;
                            eax = &var_D0;
                    }
            }
            else {
                    var_D0 = eax;
                    eax = &var_D0;
            }
            ecx = *eax;
            esi = eax[0x1];
            if (ecx == 0x0 || ecx != edi) {
                    sub_47a948();
            }
            bool_54 = true;
            bool_53 = true;
            if (esi == var_94) {
                    var_140 = var_120;
                    sub_433ae0(&var_16C);
                    sub_4194b0(decomp_var_1c4, decomp_var_1c0);
                    var_148 = ebp;
                    var_140 = var_120;
                    esp = esp - 0x14;
                    eax = sub_4194b0(&var_70, &var_148);
            }
            sub_40f400();
            esi = var_180;
            edi = var_184;
            continue;
    }
    break;
    sub_401590();
    ebp = var_FC;
    esi = var_100;
    edi = var_198;
    eax = var_1A8;
    continue;
    sub_401590();
    edi = var_14C;
    esi = var_150;
    ebx = var_164;
    ecx = var_D4;
    continue;
    sub_40f7f0();
    edi = var_198;
    ebp = var_19C;
    ebx = var_1A0;
    continue;
    sub_40f7f0();
    edi = var_198;
    ebp = var_19C;
    ebx = var_1A0;
    continue;
}
