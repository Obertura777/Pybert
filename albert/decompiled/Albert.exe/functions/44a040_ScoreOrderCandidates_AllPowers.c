// ScoreOrderCandidates_AllPowers @ 0x44a040
// hopper name: sub_44a040
// pybert name: ScoreOrderCandidates_AllPowers
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ScoreOrderCandidates_AllPowers() {
    &decomp_var_4 = &decomp_var_4 & 0xfffffff8;
    edx = 0x0;
    decomp_var_78 = ecx[0x1367] - ecx[0x134f] + CARRY(EFLAGS(cf));
    esp = esp - 0x100;
    decomp_var_dc = 0x0;
    if (*(ecx[0x2] + 0x2404) <= 0x0) goto loc_44b752;
    goto loc_44a093;

loc_44b752:
    &decomp_var_bc = ebp;
    return;

loc_44a093:
    eax = 0x0;
    goto loc_44a0a4;

loc_44a0a4:
    esi = **(decomp_var_e0 + ((eax << 0x4) - eax) * 0x8 + 0x3620);
    edi = decomp_var_e0 + ((eax << 0x4) - eax) * 0x8 + 0x361c;
    ebx = edi;
    decomp_var_90 = 0x1;
    decomp_var_8c = 0x0;
    decomp_var_98 = 0x5d8a0000;
    decomp_var_94 = 0x1634578;
    decomp_var_d8 = edi;
    decomp_var_a8 = ebx;
    decomp_var_a4 = esi;
    goto loc_44a0f0;

loc_44a0f0:
    arg_0 = edi[0x1];
    if (ebx == 0x0 || ebx != edi) {
            sub_47a948();
    }
    if (esi != arg_0) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            ebx = 0x0;
            edi = 0x0;
            decomp_var_cc = esi[0x4];
            decomp_var_c8 = esi[0x5];
            esi = 0x0;
            decomp_var_ac = decomp_var_d8;
            do {
                    eax = sub_41c1e0(&decomp_var_cc);
                    esp = esp - 0x14;
                    ebx = ebx + sub_47bb70(*(arg_4 + esi * 0x8), *(arg_4 + esi * 0x8 + 0x4), *eax, eax[0x1]);
                    edi = edi + edx + CARRY(EFLAGS(cf));
                    decomp_var_ac = decomp_var_ac + 0xc;
                    esi = esi + 0x1;
            } while (esi < 0xa);
            esi = decomp_var_dc;
            if (*(int8_t *)byte_baed6c == 0x1 && *byte_624124 != esi) {
                    eax = sub_41c1e0(&decomp_var_cc);
                    esp = esp - 0x14;
                    ebx = ebx + sub_47bb70(decomp_var_68, decomp_var_64, *eax, eax[0x1]);
                    edi = edi + edx + CARRY(EFLAGS(cf));
            }
            bool_35 = edi > decomp_var_8c;
            if (edi >= decomp_var_8c && (bool_35 || ebx > decomp_var_90)) {
                    decomp_var_90 = ebx;
                    decomp_var_8c = edi;
            }
            bool_42 = edi < decomp_var_94;
            if (edi <= decomp_var_94 && (bool_42 || ebx < decomp_var_98)) {
                    decomp_var_98 = ebx;
                    decomp_var_94 = edi;
            }
            esp = esp - 0x4;
            eax = sub_41c1e0(&decomp_var_cc);
            *eax = ebx;
            eax[0x1] = edi;
            sub_40f6f0();
            esi = decomp_var_a4;
            ebx = decomp_var_a8;
            edi = decomp_var_d8;
            continue;
    }
    break;
    edx = decomp_var_98 | decomp_var_94;
    if (edx == 0x0) {
            decomp_var_98 = 0x1;
            decomp_var_94 = 0x0;
    }
    esp = esp - 0x10;
    eax = sub_47bac0(decomp_var_90, decomp_var_8c, 0x64, 0x0);
    ecx = decomp_var_98;
    decomp_var_80 = eax;
    decomp_var_7c = edx;
    if (ecx == eax) {
            esi = decomp_var_94;
            if (esi == edx) {
                    decomp_var_80 = ecx + 0x1;
                    decomp_var_7c = esi + 0x0 + CARRY(EFLAGS(cf));
            }
    }
    esi = *edi[0x1];
    ebx = edi;
    decomp_var_a4 = esi;
    goto loc_44a290;

loc_44a290:
    decomp_var_28 = edi[0x1];
    if (ebx == 0x0 || ebx != edi) {
            sub_47a948();
    }
    if (esi == decomp_var_28) goto .l111;
    goto loc_44a2b4;

.l111:
    break;

loc_44a2b4:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    decomp_var_b8 = esi[0x4];
    decomp_var_b4 = esi[0x5];
    esi = decomp_var_cc + (decomp_var_c8 + decomp_var_c8 * 0x2) * 0x4 + 0x4000;
    edx = &decomp_var_b8;
    esp = esp - 0x4;
    eax = sub_41c1e0(edx);
    ecx = eax[0x1];
    bool_2123 = ecx < decomp_var_68;
    if (ecx > decomp_var_68) {
            eax = sub_41c1e0(&decomp_var_b8);
            ebx = sub_47bac0(sub_47bb70(*eax, eax[0x1], 0x3e8, 0x0), edx, decomp_var_7c, decomp_var_78) + 0xf;
            esp = esp - 0x28;
            decomp_var_e0 = &decomp_var_b8;
            eax = sub_41c1e0(decomp_var_e0);
            *eax = ebx;
            eax[0x1] = edx + 0x0 + CARRY(EFLAGS(cf));
            edi = decomp_var_c4;
            esp = esp - 0x4;
            eax = sub_41c1e0(&decomp_var_7c);
            ecx = eax[0x1];
            ebx = (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c;
            bool_2135 = ecx < ebx[0x156c3b];
            bool_2133 = ecx > ebx[0x156c3b];
            if (!bool_2135 && (bool_2133 || *eax > ebx[0x156c3a])) {
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&decomp_var_7c);
                    ebx[0x156c3a] = *eax;
                    ebx[0x156c3b] = eax[0x1];
            }
            esp = esp - 0x4;
            decomp_var_a4 = &decomp_var_7c;
            eax = sub_41c1e0(decomp_var_a4);
            ecx = eax[0x1];
            bool_2122 = ecx > ebx[0x15423b];
            bool_2120 = ecx < ebx[0x15423b];
            if (bool_2122) {
                    sub_40f6f0();
                    esi = decomp_var_54;
                    ebx = decomp_var_58;
                    continue;
            }
            if (bool_2120) {
                    esp = esp - 0x4;
                    decomp_var_a4 = &decomp_var_7c;
                    eax = sub_41c1e0(decomp_var_a4);
                    ebx[0x15423a] = *eax;
                    ebx[0x15423b] = eax[0x1];
                    sub_40f6f0();
                    esi = decomp_var_54;
                    ebx = decomp_var_58;
                    continue;
            }
            if (*eax < ebx[0x15423a]) {
                    esp = esp - 0x4;
                    decomp_var_a4 = &decomp_var_7c;
                    eax = sub_41c1e0(decomp_var_a4);
                    ebx[0x15423a] = *eax;
                    ebx[0x15423b] = eax[0x1];
                    sub_40f6f0();
                    esi = decomp_var_54;
                    ebx = decomp_var_58;
                    continue;
            }
            sub_40f6f0();
            esi = decomp_var_54;
            ebx = decomp_var_58;
            continue;
    }
    if (bool_2123) goto .l71;
    goto loc_44a302;
    esi = edi;
    decomp_var_94 = esi;
    decomp_var_90 = *edi[0x1];
    &decomp_var_dc = &decomp_var_dc;
    goto loc_44a500;

.l71:
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_b8);
    if ((*eax | eax[0x1]) != 0x0) goto loc_44a32a;
    goto .l74;

loc_44a302:
    edx = *eax;
    if (edx >= decomp_var_6c) goto loc_44a3f4;
    goto loc_44a30e;

loc_44a500:
    ebx = edi[0x1];
    if (esi == 0x0 || esi != edi) {
            sub_47a948();
    }
    if (decomp_var_90 != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (decomp_var_90 == esi[0x1]) {
                    sub_47a948();
            }
            edx = decomp_var_90[0x5];
            ebx = decomp_var_90[0x4];
            decomp_var_b8 = ebx;
            decomp_var_b4 = edx;
            if (*(int16_t *)word_4c6c08 != edx) {
                    sub_40f6f0();
                    esi = decomp_var_94;
                    edi = decomp_var_c4;
                    continue;
            }
            edi = decomp_var_cc + (decomp_var_c8 + decomp_var_c8 * 0x2) * 0x4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_e0 = &decomp_var_b8;
            eax = sub_41c1e0(decomp_var_e0);
            ecx = eax[0x1];
            bool_72 = ecx < *(((decomp_var_c8 << 0x8) + ebx) * 0x8 + 0x55b0ec);
            esi = ((decomp_var_c8 << 0x8) + ebx) * 0x8 + 0x55b0e8;
            if (ecx > *(((decomp_var_c8 << 0x8) + ebx) * 0x8 + 0x55b0ec)) {
                    sub_40f6f0();
                    esi = decomp_var_94;
                    edi = decomp_var_c4;
                    continue;
            }
            if (bool_72) {
                    eax = sub_41c1e0(&decomp_var_b8);
                    esp = esp - 0x8;
                    decomp_var_e0 = &decomp_var_b8;
                    ebx = eax;
                    asm { fild       qword [esp+0xdc+-68] };
                    asm { fmul       qword [qword_value_4599075939470750515] };
                    asm { fild       qword [ebx] };
                    asm { faddp      st1 };
                    *ebx = sub_47b5f6();
                    ebx[0x1] = edx;
                    sub_40f6f0();
                    esi = decomp_var_94;
                    edi = decomp_var_c4;
                    continue;
            }
            if (*eax < *esi) {
                    eax = sub_41c1e0(&decomp_var_b8);
                    esp = esp - 0x8;
                    decomp_var_e0 = &decomp_var_b8;
                    ebx = eax;
                    asm { fild       qword [esp+0xdc+-68] };
                    asm { fmul       qword [qword_value_4599075939470750515] };
                    asm { fild       qword [ebx] };
                    asm { faddp      st1 };
                    *ebx = sub_47b5f6();
                    ebx[0x1] = edx;
                    sub_40f6f0();
                    esi = decomp_var_94;
                    edi = decomp_var_c4;
                    continue;
            }
            sub_40f6f0();
            esi = decomp_var_94;
            edi = decomp_var_c4;
            continue;
    }
    break;

loc_44a32a:
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_b8);
    if (*eax != decomp_var_84) goto .l68;
    goto .l73;

.l74:
    esp = esp - 0x4;
    decomp_var_e0 = &decomp_var_b8;
    goto .l66;

loc_44a3f4:
    eax = sub_41c1e0(&decomp_var_b8);
    ebx = sub_47bac0(sub_47bb70(*eax, eax[0x1], 0x3e8, 0x0), edx, decomp_var_7c, decomp_var_78) + 0xf;
    esp = esp - 0x28;
    decomp_var_e0 = &decomp_var_b8;
    eax = sub_41c1e0(decomp_var_e0);
    *eax = ebx;
    eax[0x1] = edx + 0x0 + CARRY(EFLAGS(cf));
    edi = decomp_var_c4;
    goto loc_44a443;

loc_44a30e:
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_b8);
    if ((*eax | eax[0x1]) != 0x0) goto .l70;
    goto loc_44a323;
    ebx = *(*(decomp_var_c8 + decomp_var_c8 * 0x2 + decomp_var_c8 + decomp_var_c8 * 0x2 + decomp_var_c8 + decomp_var_c8 * 0x2 + decomp_var_c8 + decomp_var_c8 * 0x2 + 0xbc202c) + 0x4);
    esi = decomp_var_c8 + decomp_var_c8 * 0x2 + decomp_var_c8 + decomp_var_c8 * 0x2 + decomp_var_c8 + decomp_var_c8 * 0x2 + decomp_var_c8 + decomp_var_c8 * 0x2 + 0xbc2028;
    edi = ebx;
    if (ebx[0x21] == 0x0) {
            &decomp_var_dc = &decomp_var_dc;
            do {
                    sub_40faf0(edi[0x2]);
                    edi = *edi;
                    decomp_var_e0 = ebx;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebx = edi;
            } while (edi[0x21] == 0x0);
    }
    eax = esi[0x1];
    ecx = decomp_var_cc;
    eax[0x1] = eax;
    eax = esi[0x1];
    esi[0x2] = 0x0;
    *eax = eax;
    esi = esi[0x1];
    esi[0x2] = esi;
    eax = ecx[0x2];
    edi = 0x0;
    if (eax[0x900] <= 0x0) goto loc_44a798;
    goto loc_44a669;

.l68:
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_b8);
    asm { fild       qword [eax] };
    asm { fld        qword [qword_value_4602678819172646912] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-76] };
    asm { fild       qword [esp+0xdc+-108] };
    asm { fld        qword [qword_value_4602678819172646912] };
    sub_47b370();
    asm { fdivr      qword [esp+0xdc+-76] };
    asm { fmul       qword [qword_value_4621819117588971520] };
    asm { fadd       qword [qword_value_4618441417868443648+8] };
    eax = sub_47b5f6();
    esp = esp - 0x4;
    decomp_var_e0 = &decomp_var_b8;
    ebx = eax;
    eax = sub_41c1e0(decomp_var_e0);
    *eax = ebx;
    eax[0x1] = edx;
    edi = decomp_var_c4;
    goto .l67;

.l73:
    edx = eax[0x1];
    if (edx != decomp_var_80) goto .l68;
    goto .l65;

.l66:
    eax = sub_41c1e0(decomp_var_cc);
    *eax = 0x1;
    eax[0x1] = 0x0;
    goto .l67;

loc_44a443:
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_7c);
    ecx = eax[0x1];
    ebx = (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c;
    bool_2134 = ecx > ebx[0x156c3b];
    if (ecx >= ebx[0x156c3b] && (bool_2134 || *eax > ebx[0x156c3a])) {
            esp = esp - 0x4;
            eax = sub_41c1e0(&decomp_var_7c);
            ebx[0x156c3a] = *eax;
            ebx[0x156c3b] = eax[0x1];
    }
    esp = esp - 0x4;
    decomp_var_a4 = &decomp_var_7c;
    eax = sub_41c1e0(decomp_var_a4);
    ecx = eax[0x1];
    bool_2149 = ecx > ebx[0x15423b];
    bool_2128 = ecx < ebx[0x15423b];
    if (bool_2149) {
            sub_40f6f0();
            esi = decomp_var_54;
            ebx = decomp_var_58;
            continue;
    }
    if (bool_2128) {
            esp = esp - 0x4;
            decomp_var_a4 = &decomp_var_7c;
            eax = sub_41c1e0(decomp_var_a4);
            ebx[0x15423a] = *eax;
            ebx[0x15423b] = eax[0x1];
            sub_40f6f0();
            esi = decomp_var_54;
            ebx = decomp_var_58;
            continue;
    }
    if (*eax < ebx[0x15423a]) {
            esp = esp - 0x4;
            decomp_var_a4 = &decomp_var_7c;
            eax = sub_41c1e0(decomp_var_a4);
            ebx[0x15423a] = *eax;
            ebx[0x15423b] = eax[0x1];
            sub_40f6f0();
            esi = decomp_var_54;
            ebx = decomp_var_58;
            continue;
    }
    sub_40f6f0();
    esi = decomp_var_54;
    ebx = decomp_var_58;
    continue;

.l70:
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_b8);
    if (*eax != decomp_var_84) goto loc_44a360;
    goto loc_44a33c;

loc_44a323:
    esp = esp - 0x4;
    decomp_var_e0 = &decomp_var_b8;
    goto loc_44a34c;

loc_44a798:
    edi = ecx[0x2];
    esi = *edi[0x915];
    edi = edi + 0x2450;
    decomp_var_98 = edi;
    decomp_var_94 = esi;
    goto loc_44a7b1;

loc_44a669:
    esi = 0x0;
    goto loc_44a670;

.l67:
    esp = esp - 0x4;
    decomp_var_b8 = &decomp_var_90;
    eax = sub_41c1e0(decomp_var_b8);
    bool_2145 = eax[0x1] > 0x0;
    if (eax[0x1] >= 0x0 && (bool_2145 || *eax > 0xa)) {
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            *eax = 0xa;
            eax[0x1] = 0x0;
    }
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_7c);
    ecx = eax[0x1];
    ebx = (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c + (decomp_var_8c << 0x8) + decomp_var_7c;
    bool_2153 = ecx > ebx[0x156c3b];
    if (ecx >= ebx[0x156c3b] && (bool_2153 || *eax > ebx[0x156c3a])) {
            esp = esp - 0x4;
            eax = sub_41c1e0(&decomp_var_7c);
            ebx[0x156c3a] = *eax;
            ebx[0x156c3b] = eax[0x1];
    }
    esp = esp - 0x4;
    decomp_var_a4 = &decomp_var_7c;
    eax = sub_41c1e0(decomp_var_a4);
    ecx = eax[0x1];
    bool_2148 = ecx < ebx[0x15423b];
    if (ecx > ebx[0x15423b]) {
            sub_40f6f0();
            esi = decomp_var_54;
            ebx = decomp_var_58;
            continue;
    }
    if (bool_2148) {
            esp = esp - 0x4;
            decomp_var_a4 = &decomp_var_7c;
            eax = sub_41c1e0(decomp_var_a4);
            ebx[0x15423a] = *eax;
            ebx[0x15423b] = eax[0x1];
            sub_40f6f0();
            esi = decomp_var_54;
            ebx = decomp_var_58;
            continue;
    }
    if (*eax < ebx[0x15423a]) {
            esp = esp - 0x4;
            decomp_var_a4 = &decomp_var_7c;
            eax = sub_41c1e0(decomp_var_a4);
            ebx[0x15423a] = *eax;
            ebx[0x15423b] = eax[0x1];
            sub_40f6f0();
            esi = decomp_var_54;
            ebx = decomp_var_58;
            continue;
    }
    sub_40f6f0();
    esi = decomp_var_54;
    ebx = decomp_var_58;
    continue;

.l65:
    esp = esp - 0x4;
    decomp_var_e0 = &decomp_var_b8;
    goto .l66;

loc_44a360:
    esp = esp - 0x4;
    eax = sub_41c1e0(&decomp_var_b8);
    asm { fild       qword [eax] };
    asm { fld        qword [qword_value_4602678819172646912] };
    sub_47b370();
    asm { fstp       qword [esp+0xdc+-76] };
    asm { fild       qword [esp+0xdc+-108] };
    asm { fld        qword [qword_value_4602678819172646912] };
    sub_47b370();
    asm { fdivr      qword [esp+0xdc+-76] };
    asm { fmul       qword [qword_value_4621819117588971520] };
    asm { fadd       qword [qword_value_4618441417868443648+8] };
    eax = sub_47b5f6();
    esp = esp - 0x4;
    decomp_var_e0 = &decomp_var_b8;
    ebx = eax;
    eax = sub_41c1e0(decomp_var_e0);
    *eax = ebx;
    eax[0x1] = edx;
    edi = decomp_var_c4;
    goto loc_44a3c0;

loc_44a33c:
    edx = eax[0x1];
    if (edx != decomp_var_80) goto loc_44a360;
    goto loc_44a345;

loc_44a34c:
    eax = sub_41c1e0(decomp_var_cc);
    *eax = 0x1;
    eax[0x1] = 0x0;
    goto loc_44a3c0;

loc_44a7b1:
    edx = 0x0;
    eax = decomp_var_b8[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
            edx = 0x0;
    }
    if (esi != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            edx = decomp_var_b4;
            if (esi[0x6] != edx) {
                    sub_401390();
                    esi = decomp_var_94;
                    edi = decomp_var_98;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                            temp_0 = 0x1;
                    }
                    else {
                            temp_0 = 0x0;
                    }
            }
            else {
                    temp_0 = 0x0;
            }
            break;
    }
    else {
            temp_0 = 0x2;
            break;
    }
    goto .l26;

loc_44a670:
    if (*(int8_t *)(esi + eax + 0x3) == 0x0) goto loc_44a693;
    goto loc_44a677;

loc_44a3c0:
    esp = esp - 0x4;
    decomp_var_b8 = &decomp_var_90;
    eax = sub_41c1e0(decomp_var_b8);
    bool_2127 = eax[0x1] > 0x0;
    if (eax[0x1] >= 0x0 && (bool_2127 || *eax > 0xa)) {
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            *eax = 0xa;
            eax[0x1] = 0x0;
    }
    goto loc_44a443;

loc_44a345:
    esp = esp - 0x4;
    decomp_var_e0 = &decomp_var_b8;
    goto loc_44a34c;

.l26:
    if (temp_0 == 0x0) goto .l12;
    goto .l140;

loc_44a693:
    eax = (decomp_var_c8 << 0x8) + edi + (decomp_var_c8 << 0x8) + edi + (decomp_var_c8 << 0x8) + edi + (decomp_var_c8 << 0x8) + edi + (decomp_var_c8 << 0x8) + edi + (decomp_var_c8 << 0x8) + edi + (decomp_var_c8 << 0x8) + edi + (decomp_var_c8 << 0x8) + edi;
    bool_1207 = eax[0x18103b] > 0x0;
    bool_922 = eax[0x18103b] < 0x0;
    if (bool_1207) goto loc_44a777;
    goto loc_44a6ae;

loc_44a677:
    eax = *(int16_t *)(esi + eax + 0x20);
    bool_761 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_761) {
            eax = 0x14;
    }
    if (eax != decomp_var_c8) goto loc_44a777;
    goto loc_44a693;

.l12:
    temp_1 = 0x0;
    goto .l161;

.l140:
    if (temp_0 == 0x1) goto .l159;
    goto loc_44a9d4;

loc_44a777:
    ecx = decomp_var_b8;
    eax = ecx[0x2];
    edi = edi + 0x1;
    esi = decomp_var_9c + 0x24;
    decomp_var_9c = esi;
    if (edi < eax[0x900]) {
            continue;
    }
    break;

loc_44a6ae:
    if (bool_922) goto loc_44a6bc;
    goto loc_44a6b0;

.l161:
    break;

.l159:
    temp_1 = 0x0;
    goto .l161;

loc_44a9d4:
    eax = decomp_var_b8[0x2];
    decomp_var_84 = edx;
    if (eax[0x900] <= edx) goto loc_44ab8d;
    goto loc_44a9eb;

loc_44a6bc:
    if (eax[0x17903a] != 0x2) goto loc_44a6d1;
    goto loc_44a6c5;

loc_44a6b0:
    if (eax[0x18103a] <= 0x0) {
            if (eax[0x17903a] == 0x2) {
                    if (eax[0x17903b] != 0x0) {
                            ecx = eax[0x163e3b];
                            bool_295 = ecx > 0x0;
                            esi = eax[0x163e3a];
                            if (ecx >= 0x0) {
                                    if (!bool_295) {
                                            if (esi > 0x0) {
                                                    if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                                                            if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x1;
                                                                    eax[0x17ba3b] = 0x0;
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    bool_1004 = esi < 0x1;
                                                                    bool_972 = esi > 0x1;
                                                                    if (esi == 0x1) {
                                                                            bool_987 = ecx < 0x0;
                                                                            bool_725 = ecx > 0x0;
                                                                            if (ecx == 0x0) {
                                                                                    bool_1524 = eax[0x14833a] != esi;
                                                                                    bool_280 = eax[0x14833a] < esi;
                                                                                    bool_252 = eax[0x14833a] > esi;
                                                                                    if (!bool_1524) {
                                                                                            edx = 0x0;
                                                                                            bool_1407 = eax[0x14833b] < 0x0;
                                                                                            bool_372 = eax[0x14833b] != 0x0;
                                                                                            bool_360 = eax[0x14833b] > 0x0;
                                                                                            if (!bool_372) {
                                                                                                    ebx = eax[0x14d73a];
                                                                                                    ebx = ebx | eax[0x14d73b];
                                                                                                    bool_1882 = ebx > 0x0;
                                                                                                    bool_1619 = ebx < 0x0;
                                                                                                    if (ebx == 0x0) {
                                                                                                            eax[0x17ba3a] = esi;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            if (!bool_1619) {
                                                                                                                    if (!bool_1882) {
                                                                                                                            if (esi > edx) {
                                                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                                                            edx = 0x0;
                                                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                                            }
                                                                                                                                    }
                                                                                                                                    ecx = decomp_var_b8;
                                                                                                                                    eax = ecx[0x2];
                                                                                                                                    edi = edi + 0x1;
                                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                                    decomp_var_9c = esi;
                                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                            else {
                                                                                                                                    ecx = decomp_var_b8;
                                                                                                                                    eax = ecx[0x2];
                                                                                                                                    edi = edi + 0x1;
                                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                                    decomp_var_9c = esi;
                                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                                            continue;
                                                                                                                                    }
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (!bool_1407) {
                                                                                                            if (!bool_360) {
                                                                                                                    if (esi > 0x0) {
                                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_280) {
                                                                                                    if (!bool_252) {
                                                                                                            edx = 0x0;
                                                                                                            if (esi > 0x0) {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_987) {
                                                                                            if (!bool_725) {
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                            edx = 0x0;
                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1004) {
                                                                                    if (!bool_972) {
                                                                                            edx = 0x0;
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            bool_398 = esi < 0x1;
                                                            bool_375 = esi > 0x1;
                                                            if (esi == 0x1) {
                                                                    edx = 0x0;
                                                                    bool_1771 = ecx > 0x0;
                                                                    bool_256 = ecx < 0x0;
                                                                    if (ecx == 0x0) {
                                                                            bool_410 = eax[0x14833a] < esi;
                                                                            bool_387 = eax[0x14833a] > esi;
                                                                            if (eax[0x14833a] == esi) {
                                                                                    bool_1123 = eax[0x14833b] != edx;
                                                                                    bool_884 = eax[0x14833b] < edx;
                                                                                    bool_482 = eax[0x14833b] > edx;
                                                                                    if (!bool_1123) {
                                                                                            ebx = eax[0x14d73a];
                                                                                            ebx = ebx | eax[0x14d73b];
                                                                                            bool_1700 = ebx < 0x0;
                                                                                            bool_677 = ebx > 0x0;
                                                                                            if (ebx == 0x0) {
                                                                                                    eax[0x17ba3a] = esi;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    if (!bool_1700) {
                                                                                                            if (!bool_677) {
                                                                                                                    if (esi > edx) {
                                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_884) {
                                                                                                    if (!bool_482) {
                                                                                                            if (esi > edx) {
                                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                                            edx = 0x0;
                                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_410) {
                                                                                            if (!bool_387) {
                                                                                                    edx = 0x0;
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_256) {
                                                                                    if (!bool_1771) {
                                                                                            if (esi > edx) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_398) {
                                                                            if (!bool_375) {
                                                                                    edx = 0x0;
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    bool_1744 = esi > 0x1;
                                                    bool_1310 = esi < 0x1;
                                                    if (esi == 0x1) {
                                                            edx = 0x0;
                                                            bool_858 = ecx < 0x0;
                                                            bool_571 = ecx > 0x0;
                                                            if (ecx == 0x0) {
                                                                    bool_924 = eax[0x14833a] != esi;
                                                                    bool_369 = eax[0x14833a] < esi;
                                                                    bool_340 = eax[0x14833a] > esi;
                                                                    if (!bool_924) {
                                                                            bool_1102 = eax[0x14833b] != edx;
                                                                            bool_868 = eax[0x14833b] < edx;
                                                                            bool_443 = eax[0x14833b] > edx;
                                                                            if (!bool_1102) {
                                                                                    ebx = eax[0x14d73a];
                                                                                    ebx = ebx | eax[0x14d73b];
                                                                                    bool_1241 = ebx > 0x0;
                                                                                    bool_201 = ebx < 0x0;
                                                                                    if (ebx == 0x0) {
                                                                                            eax[0x17ba3a] = esi;
                                                                                            eax[0x17ba3b] = edx;
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_201) {
                                                                                                    if (!bool_1241) {
                                                                                                            if (esi > edx) {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_868) {
                                                                                            if (!bool_443) {
                                                                                                    if (esi > edx) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_369) {
                                                                                    if (!bool_340) {
                                                                                            if (esi > edx) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_858) {
                                                                            if (!bool_571) {
                                                                                    if (esi > edx) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1310) {
                                                                    if (!bool_1744) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                                                    if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                                                            eax[0x17ba3a] = 0x1;
                                                            eax[0x17ba3b] = 0x0;
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            bool_1205 = esi < 0x1;
                                                            bool_1191 = esi > 0x1;
                                                            if (esi == 0x1) {
                                                                    bool_1777 = ecx < 0x0;
                                                                    bool_1499 = ecx > 0x0;
                                                                    if (ecx == 0x0) {
                                                                            bool_1194 = eax[0x14833a] != esi;
                                                                            bool_1037 = eax[0x14833a] < esi;
                                                                            bool_1006 = eax[0x14833a] > esi;
                                                                            if (!bool_1194) {
                                                                                    edx = 0x0;
                                                                                    bool_1717 = eax[0x14833b] != 0x0;
                                                                                    bool_1465 = eax[0x14833b] < 0x0;
                                                                                    bool_1109 = eax[0x14833b] > 0x0;
                                                                                    if (!bool_1717) {
                                                                                            ebx = eax[0x14d73a];
                                                                                            ebx = ebx | eax[0x14d73b];
                                                                                            bool_1750 = ebx < 0x0;
                                                                                            bool_1454 = ebx > 0x0;
                                                                                            if (ebx == 0x0) {
                                                                                                    eax[0x17ba3a] = esi;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    if (!bool_1750) {
                                                                                                            if (!bool_1454) {
                                                                                                                    if (esi > edx) {
                                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_1465) {
                                                                                                    if (!bool_1109) {
                                                                                                            if (esi > edx) {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_1037) {
                                                                                            if (!bool_1006) {
                                                                                                    edx = 0x0;
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                            edx = 0x0;
                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1777) {
                                                                                    if (!bool_1499) {
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1205) {
                                                                            if (!bool_1191) {
                                                                                    edx = 0x0;
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    bool_1352 = esi < 0x1;
                                                    bool_1334 = esi > 0x1;
                                                    if (esi == 0x1) {
                                                            bool_1025 = ecx < 0x0;
                                                            bool_760 = ecx > 0x0;
                                                            if (ecx == 0x0) {
                                                                    bool_1350 = eax[0x14833a] > esi;
                                                                    bool_1344 = eax[0x14833a] < esi;
                                                                    if (eax[0x14833a] == esi) {
                                                                            bool_1821 = eax[0x14833b] < 0x0;
                                                                            bool_1406 = eax[0x14833b] > 0x0;
                                                                            if (eax[0x14833b] == 0x0) {
                                                                                    ebx = eax[0x14d73a];
                                                                                    ebx = ebx | eax[0x14d73b];
                                                                                    bool_1905 = ebx < 0x0;
                                                                                    bool_616 = ebx > 0x0;
                                                                                    if (ebx == 0x0) {
                                                                                            eax[0x17ba3a] = esi;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_1905) {
                                                                                                    if (!bool_616) {
                                                                                                            if (esi > 0x0) {
                                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                                            edx = 0x0;
                                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_1821) {
                                                                                            if (!bool_1406) {
                                                                                                    edx = 0x0;
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                            edx = 0x0;
                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1344) {
                                                                                    if (!bool_1350) {
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                            edx = 0x0;
                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1025) {
                                                                            if (!bool_760) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1352) {
                                                                    if (!bool_1334) {
                                                                            edx = 0x0;
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else {
                                    bool_1725 = esi < 0x1;
                                    bool_1703 = esi > 0x1;
                                    if (esi == 0x1) {
                                            bool_1462 = ecx > 0x0;
                                            bool_988 = ecx < 0x0;
                                            if (ecx == 0x0) {
                                                    bool_1055 = eax[0x14833a] != esi;
                                                    bool_456 = eax[0x14833a] < esi;
                                                    bool_435 = eax[0x14833a] > esi;
                                                    if (!bool_1055) {
                                                            edx = 0x0;
                                                            bool_1186 = eax[0x14833b] != 0x0;
                                                            bool_943 = eax[0x14833b] < 0x0;
                                                            bool_525 = eax[0x14833b] > 0x0;
                                                            if (!bool_1186) {
                                                                    ebx = eax[0x14d73a];
                                                                    ebx = ebx | eax[0x14d73b];
                                                                    bool_1367 = ebx > 0x0;
                                                                    bool_414 = ebx < 0x0;
                                                                    if (ebx == 0x0) {
                                                                            eax[0x17ba3a] = esi;
                                                                            eax[0x17ba3b] = edx;
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if (!bool_414) {
                                                                                    if (!bool_1367) {
                                                                                            edx = 0x0;
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_943) {
                                                                            if (!bool_525) {
                                                                                    if (esi > edx) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_456) {
                                                                    if (!bool_435) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_988) {
                                                            if (!bool_1462) {
                                                                    edx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1) {
                                                                            edx = 0x0;
                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_1725) {
                                                    if (!bool_1703) {
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = 0x0;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                    }
                    else {
                            ecx = decomp_var_b8;
                            eax = ecx[0x2];
                            edi = edi + 0x1;
                            esi = decomp_var_9c + 0x24;
                            decomp_var_9c = esi;
                            if (edi < eax[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    ecx = eax[0x163e3b];
                    bool_876 = ecx > 0x0;
                    esi = eax[0x163e3a];
                    if (ecx >= 0x0) {
                            if (!bool_876) {
                                    if (esi > 0x0) {
                                            if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                                                    if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                                                            eax[0x17ba3a] = 0x1;
                                                            eax[0x17ba3b] = 0x0;
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            bool_786 = esi < 0x1;
                                                            bool_759 = esi > 0x1;
                                                            if (esi == 0x1) {
                                                                    edx = 0x0;
                                                                    bool_1820 = ecx < 0x0;
                                                                    bool_1546 = ecx > 0x0;
                                                                    if (ecx == 0x0) {
                                                                            bool_1523 = eax[0x14833a] < esi;
                                                                            bool_1496 = eax[0x14833a] > esi;
                                                                            if (eax[0x14833a] == esi) {
                                                                                    edx = 0x0;
                                                                                    bool_1607 = eax[0x14833b] > 0x0;
                                                                                    bool_1431 = eax[0x14833b] < 0x0;
                                                                                    if (eax[0x14833b] == 0x0) {
                                                                                            ebx = eax[0x14d73a];
                                                                                            ebx = ebx | eax[0x14d73b];
                                                                                            bool_1740 = ebx > 0x0;
                                                                                            bool_1172 = ebx < 0x0;
                                                                                            if (ebx == 0x0) {
                                                                                                    eax[0x17ba3a] = esi;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    if (!bool_1172) {
                                                                                                            if (!bool_1740) {
                                                                                                                    if (esi > edx) {
                                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                                    }
                                                                                                                            }
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                                    else {
                                                                                                                            ecx = decomp_var_b8;
                                                                                                                            eax = ecx[0x2];
                                                                                                                            edi = edi + 0x1;
                                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                                            decomp_var_9c = esi;
                                                                                                                            if (edi < eax[0x900]) {
                                                                                                                                    continue;
                                                                                                                            }
                                                                                                                            break;
                                                                                                                    }
                                                                                                            }
                                                                                                            else {
                                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                                            edx = 0x0;
                                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_1431) {
                                                                                                    if (!bool_1607) {
                                                                                                            if (esi > 0x0) {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_1523) {
                                                                                            if (!bool_1496) {
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                                    edx = 0x0;
                                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1820) {
                                                                                    if (!bool_1546) {
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_786) {
                                                                            if (!bool_759) {
                                                                                    edx = 0x0;
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                            }
                                            else {
                                                    bool_1478 = esi < 0x1;
                                                    bool_1453 = esi > 0x1;
                                                    if (esi == 0x1) {
                                                            bool_1138 = ecx < 0x0;
                                                            bool_877 = ecx > 0x0;
                                                            if (ecx == 0x0) {
                                                                    bool_1151 = eax[0x14833a] < esi;
                                                                    bool_1014 = eax[0x14833a] != esi;
                                                                    bool_274 = eax[0x14833a] > esi;
                                                                    if (!bool_1014) {
                                                                            bool_1835 = eax[0x14833b] != 0x0;
                                                                            bool_1593 = eax[0x14833b] < 0x0;
                                                                            bool_1213 = eax[0x14833b] > 0x0;
                                                                            if (!bool_1835) {
                                                                                    ebx = eax[0x14d73a];
                                                                                    ebx = ebx | eax[0x14d73b];
                                                                                    bool_1495 = ebx > 0x0;
                                                                                    bool_726 = ebx < 0x0;
                                                                                    if (ebx == 0x0) {
                                                                                            eax[0x17ba3a] = esi;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_726) {
                                                                                                    if (!bool_1495) {
                                                                                                            if (esi > 0x0) {
                                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                                    edx = 0x0;
                                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_1593) {
                                                                                            if (!bool_1213) {
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                            edx = 0x0;
                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1151) {
                                                                                    if (!bool_274) {
                                                                                            edx = 0x0;
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1138) {
                                                                            if (!bool_877) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1478) {
                                                                    if (!bool_1453) {
                                                                            edx = 0x0;
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            bool_1648 = esi > 0x1;
                                            bool_1097 = esi < 0x1;
                                            if (esi == 0x1) {
                                                    edx = 0x0;
                                                    bool_1749 = ecx > 0x0;
                                                    bool_239 = ecx < 0x0;
                                                    if (ecx == 0x0) {
                                                            bool_956 = eax[0x14833a] < esi;
                                                            bool_935 = eax[0x14833a] > esi;
                                                            if (eax[0x14833a] == esi) {
                                                                    bool_1655 = eax[0x14833b] != edx;
                                                                    bool_1396 = eax[0x14833b] < edx;
                                                                    bool_1039 = eax[0x14833b] > edx;
                                                                    if (!bool_1655) {
                                                                            ebx = eax[0x14d73a];
                                                                            ebx = ebx | eax[0x14d73b];
                                                                            bool_1889 = ebx > 0x0;
                                                                            bool_799 = ebx < 0x0;
                                                                            if (ebx == 0x0) {
                                                                                    eax[0x17ba3a] = esi;
                                                                                    eax[0x17ba3b] = edx;
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    if (!bool_799) {
                                                                                            if (!bool_1889) {
                                                                                                    if (esi > edx) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1396) {
                                                                                    if (!bool_1039) {
                                                                                            if (esi > edx) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_956) {
                                                                            if (!bool_935) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_239) {
                                                                    if (!bool_1749) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_1097) {
                                                            if (!bool_1648) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                                            if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                                                    eax[0x17ba3a] = 0x1;
                                                    eax[0x17ba3b] = 0x0;
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    bool_1345 = esi < 0x1;
                                                    bool_1330 = esi > 0x1;
                                                    if (esi == 0x1) {
                                                            bool_1027 = ecx < 0x0;
                                                            bool_767 = ecx > 0x0;
                                                            if (ecx == 0x0) {
                                                                    bool_1304 = eax[0x14833a] < esi;
                                                                    bool_1281 = eax[0x14833a] > esi;
                                                                    if (eax[0x14833a] == esi) {
                                                                            bool_1879 = eax[0x14833b] < 0x0;
                                                                            bool_1357 = eax[0x14833b] > 0x0;
                                                                            if (eax[0x14833b] == 0x0) {
                                                                                    ebx = eax[0x14d73a];
                                                                                    ebx = ebx | eax[0x14d73b];
                                                                                    bool_1912 = ebx < 0x0;
                                                                                    bool_929 = ebx > 0x0;
                                                                                    if (ebx == 0x0) {
                                                                                            eax[0x17ba3a] = esi;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_1912) {
                                                                                                    if (!bool_929) {
                                                                                                            if (esi > 0x0) {
                                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                                            edx = 0x0;
                                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_1879) {
                                                                                            if (!bool_1357) {
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                            edx = 0x0;
                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1304) {
                                                                                    if (!bool_1281) {
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                            edx = 0x0;
                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1027) {
                                                                            if (!bool_767) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1345) {
                                                                    if (!bool_1330) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            bool_1518 = esi < 0x1;
                                            bool_1493 = esi > 0x1;
                                            if (esi == 0x1) {
                                                    bool_1198 = ecx < 0x0;
                                                    bool_933 = ecx > 0x0;
                                                    if (ecx == 0x0) {
                                                            bool_1447 = eax[0x14833a] < esi;
                                                            bool_1423 = eax[0x14833a] > esi;
                                                            if (eax[0x14833a] == esi) {
                                                                    bool_1933 = eax[0x14833b] < 0x0;
                                                                    bool_1519 = eax[0x14833b] > 0x0;
                                                                    if (eax[0x14833b] == 0x0) {
                                                                            ebx = eax[0x14d73a];
                                                                            ebx = ebx | eax[0x14d73b];
                                                                            bool_1566 = ebx > 0x0;
                                                                            bool_327 = ebx < 0x0;
                                                                            if (ebx == 0x0) {
                                                                                    eax[0x17ba3a] = esi;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    if (!bool_327) {
                                                                                            if (!bool_1566) {
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1933) {
                                                                                    if (!bool_1519) {
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1447) {
                                                                            if (!bool_1423) {
                                                                                    edx = 0x0;
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1198) {
                                                                    if (!bool_933) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_1518) {
                                                            if (!bool_1493) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                            }
                    }
                    else {
                            bool_1515 = esi < 0x1;
                            bool_1488 = esi > 0x1;
                            if (esi == 0x1) {
                                    bool_768 = ecx < 0x0;
                                    bool_489 = ecx > 0x0;
                                    if (ecx == 0x0) {
                                            bool_1219 = eax[0x14833a] != esi;
                                            bool_666 = eax[0x14833a] < esi;
                                            bool_638 = eax[0x14833a] > esi;
                                            if (!bool_1219) {
                                                    bool_1807 = eax[0x14833b] < 0x0;
                                                    bool_738 = eax[0x14833b] > 0x0;
                                                    if (eax[0x14833b] == 0x0) {
                                                            ebx = eax[0x14d73a];
                                                            ebx = ebx | eax[0x14d73b];
                                                            bool_1665 = ebx < 0x0;
                                                            bool_1175 = ebx > 0x0;
                                                            if (ebx == 0x0) {
                                                                    eax[0x17ba3a] = esi;
                                                                    eax[0x17ba3b] = 0x0;
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    if (!bool_1665) {
                                                                            if (!bool_1175) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1807) {
                                                                    if (!bool_738) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_666) {
                                                            if (!bool_638) {
                                                                    edx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1) {
                                                                            edx = 0x0;
                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_768) {
                                                    if (!bool_489) {
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1) {
                                                                    edx = 0x0;
                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_1515) {
                                            if (!bool_1488) {
                                                    if (esi > 0x0) {
                                                            if (eax[0x14833a] == 0x1) {
                                                                    edx = 0x0;
                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = 0x0;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
            }
    }
    else {
            ecx = decomp_var_b8;
            eax = ecx[0x2];
            edi = edi + 0x1;
            esi = decomp_var_9c + 0x24;
            decomp_var_9c = esi;
            if (edi < eax[0x900]) {
                    continue;
            }
            break;
    }
    goto loc_44a798;
    if (temp_1 == 0x0) {
            sub_4075b0(esi + 0x14, decomp_var_c8);
            sub_44a840(decomp_var_c8, decomp_var_c4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, eax, eax, *eax[0x1], decomp_var_a4, decomp_var_a0, decomp_var_9c, decomp_var_98, decomp_var_94, decomp_var_90, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c);
    }
    &decomp_var_bc = ebp;
    return;

loc_44ab8d:
    ebx = decomp_var_b8;
    edi = ebx[0x2];
    esi = *edi[0x915];
    edi = edi + 0x2450;
    decomp_var_98 = edi;
    decomp_var_94 = esi;
    goto loc_44abb0;

loc_44a9eb:
    decomp_var_90 = 0x0;
    decomp_var_b0 = decomp_var_b8 + 0x2a1c;
    goto loc_44aa01;

loc_44a6d1:
    ecx = eax[0x163e3b];
    bool_195 = ecx > 0x0;
    esi = eax[0x163e3a];
    if (ecx < 0x0) goto .l41;
    goto loc_44a6e1;

loc_44a6c5:
    if (eax[0x17903b] != 0x0) {
            ecx = eax[0x163e3b];
            bool_867 = ecx > 0x0;
            esi = eax[0x163e3a];
            if (ecx >= 0x0) {
                    if (!bool_867) {
                            edx = 0x0;
                            if (esi > 0x0) {
                                    if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                                            if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                                                    eax[0x17ba3a] = 0x1;
                                                    eax[0x17ba3b] = edx;
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    bool_1653 = esi < 0x1;
                                                    bool_1627 = esi > 0x1;
                                                    if (esi == 0x1) {
                                                            bool_1935 = ecx > edx;
                                                            bool_445 = ecx < edx;
                                                            if (ecx == edx) {
                                                                    bool_1571 = eax[0x14833a] < esi;
                                                                    bool_1542 = eax[0x14833a] > esi;
                                                                    if (eax[0x14833a] == esi) {
                                                                            bool_1659 = eax[0x14833b] > edx;
                                                                            bool_1570 = eax[0x14833b] != edx;
                                                                            bool_908 = eax[0x14833b] < edx;
                                                                            if (!bool_1570) {
                                                                                    ebx = eax[0x14d73a];
                                                                                    ebx = ebx | eax[0x14d73b];
                                                                                    bool_753 = ebx > 0x0;
                                                                                    bool_299 = ebx < 0x0;
                                                                                    if (ebx == 0x0) {
                                                                                            eax[0x17ba3a] = esi;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            if (!bool_299) {
                                                                                                    if (!bool_753) {
                                                                                                            if (esi > 0x0) {
                                                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                                                            edx = 0x0;
                                                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                                            }
                                                                                                                    }
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                            else {
                                                                                                                    ecx = decomp_var_b8;
                                                                                                                    eax = ecx[0x2];
                                                                                                                    edi = edi + 0x1;
                                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                                    decomp_var_9c = esi;
                                                                                                                    if (edi < eax[0x900]) {
                                                                                                                            continue;
                                                                                                                    }
                                                                                                                    break;
                                                                                                            }
                                                                                                    }
                                                                                                    else {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (!bool_908) {
                                                                                            if (!bool_1659) {
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1571) {
                                                                                    if (!bool_1542) {
                                                                                            edx = 0x0;
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_445) {
                                                                            if (!bool_1935) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1653) {
                                                                    if (!bool_1627) {
                                                                            if (esi > edx) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                                    else {
                                            bool_946 = esi < 0x1;
                                            bool_927 = esi > 0x1;
                                            if (esi == 0x1) {
                                                    bool_1477 = ecx < 0x0;
                                                    bool_1249 = ecx > 0x0;
                                                    if (ecx == 0x0) {
                                                            bool_1444 = eax[0x14833a] != esi;
                                                            bool_494 = eax[0x14833a] < esi;
                                                            bool_469 = eax[0x14833a] > esi;
                                                            if (!bool_1444) {
                                                                    edx = 0x0;
                                                                    bool_559 = eax[0x14833b] > 0x0;
                                                                    bool_539 = eax[0x14833b] != 0x0;
                                                                    bool_298 = eax[0x14833b] < 0x0;
                                                                    if (!bool_539) {
                                                                            ebx = eax[0x14d73a];
                                                                            ebx = ebx | eax[0x14d73b];
                                                                            bool_1888 = ebx > 0x0;
                                                                            bool_654 = ebx < 0x0;
                                                                            if (ebx == 0x0) {
                                                                                    eax[0x17ba3a] = esi;
                                                                                    eax[0x17ba3b] = edx;
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    if (!bool_654) {
                                                                                            if (!bool_1888) {
                                                                                                    if (esi > edx) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = edx;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_298) {
                                                                                    if (!bool_559) {
                                                                                            if (esi > edx) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_494) {
                                                                            if (!bool_469) {
                                                                                    edx = 0x0;
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1477) {
                                                                    if (!bool_1249) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_946) {
                                                            if (!bool_927) {
                                                                    if (esi > edx) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    bool_1830 = esi > 0x1;
                                    bool_1561 = esi < 0x1;
                                    if (esi == 0x1) {
                                            bool_1873 = ecx < edx;
                                            bool_1617 = ecx > edx;
                                            if (ecx == edx) {
                                                    bool_917 = eax[0x14833a] < esi;
                                                    bool_898 = eax[0x14833a] > esi;
                                                    if (eax[0x14833a] == esi) {
                                                            bool_1609 = eax[0x14833b] != edx;
                                                            bool_1368 = eax[0x14833b] < edx;
                                                            bool_989 = eax[0x14833b] > edx;
                                                            if (!bool_1609) {
                                                                    ebx = eax[0x14d73a];
                                                                    ebx = ebx | eax[0x14d73b];
                                                                    bool_756 = ebx < 0x0;
                                                                    bool_513 = ebx > 0x0;
                                                                    if (ebx == 0x0) {
                                                                            eax[0x17ba3a] = esi;
                                                                            eax[0x17ba3b] = edx;
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if (!bool_756) {
                                                                                    if (!bool_513) {
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1368) {
                                                                            if (!bool_989) {
                                                                                    edx = 0x0;
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_917) {
                                                                    if (!bool_898) {
                                                                            if (esi > edx) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_1873) {
                                                            if (!bool_1617) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_1561) {
                                                    if (!bool_1830) {
                                                            edx = 0x0;
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = 0x0;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                    }
                    else {
                            if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                                    if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                                            eax[0x17ba3a] = 0x1;
                                            eax[0x17ba3b] = 0x0;
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            bool_944 = esi < 0x1;
                                            bool_918 = esi > 0x1;
                                            if (esi == 0x1) {
                                                    edx = 0x0;
                                                    bool_587 = ecx < 0x0;
                                                    bool_314 = ecx > 0x0;
                                                    if (ecx == 0x0) {
                                                            bool_1680 = eax[0x14833a] != esi;
                                                            bool_1356 = eax[0x14833a] < esi;
                                                            bool_1338 = eax[0x14833a] > esi;
                                                            if (!bool_1680) {
                                                                    bool_1836 = eax[0x14833b] < 0x0;
                                                                    bool_1416 = eax[0x14833b] > 0x0;
                                                                    if (eax[0x14833b] == 0x0) {
                                                                            ebx = eax[0x14d73a];
                                                                            ebx = ebx | eax[0x14d73b];
                                                                            bool_1475 = ebx < 0x0;
                                                                            bool_582 = ebx > 0x0;
                                                                            if (ebx == 0x0) {
                                                                                    eax[0x17ba3a] = esi;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    if (!bool_1475) {
                                                                                            if (!bool_582) {
                                                                                                    if (esi > 0x0) {
                                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                                    }
                                                                                                            }
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                                    else {
                                                                                                            ecx = decomp_var_b8;
                                                                                                            eax = ecx[0x2];
                                                                                                            edi = edi + 0x1;
                                                                                                            esi = decomp_var_9c + 0x24;
                                                                                                            decomp_var_9c = esi;
                                                                                                            if (edi < eax[0x900]) {
                                                                                                                    continue;
                                                                                                            }
                                                                                                            break;
                                                                                                    }
                                                                                            }
                                                                                            else {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (!bool_1836) {
                                                                                    if (!bool_1416) {
                                                                                            edx = 0x0;
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1356) {
                                                                            if (!bool_1338) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1) {
                                                                                                    edx = 0x0;
                                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = edx;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_587) {
                                                                    if (!bool_314) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_944) {
                                                            if (!bool_918) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1) {
                                                                            edx = 0x0;
                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                            }
                            else {
                                    bool_246 = esi < 0x1;
                                    bool_225 = esi > 0x1;
                                    if (esi == 0x1) {
                                            bool_854 = ecx < 0x0;
                                            bool_567 = ecx > 0x0;
                                            if (ecx == 0x0) {
                                                    bool_454 = eax[0x14833a] < esi;
                                                    bool_434 = eax[0x14833a] > esi;
                                                    if (eax[0x14833a] == esi) {
                                                            edx = 0x0;
                                                            bool_1185 = eax[0x14833b] != 0x0;
                                                            bool_940 = eax[0x14833b] < 0x0;
                                                            bool_524 = eax[0x14833b] > 0x0;
                                                            if (!bool_1185) {
                                                                    ebx = eax[0x14d73a];
                                                                    ebx = ebx | eax[0x14d73b];
                                                                    bool_1239 = ebx > 0x0;
                                                                    bool_430 = ebx < 0x0;
                                                                    if (ebx == 0x0) {
                                                                            eax[0x17ba3a] = esi;
                                                                            eax[0x17ba3b] = 0x0;
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if (!bool_430) {
                                                                                    if (!bool_1239) {
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_940) {
                                                                            if (!bool_524) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_454) {
                                                                    if (!bool_434) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_854) {
                                                            if (!bool_567) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1) {
                                                                            edx = 0x0;
                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_246) {
                                                    if (!bool_225) {
                                                            edx = 0x0;
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1) {
                                                                    edx = 0x0;
                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                    }
            }
            else {
                    bool_717 = esi < 0x1;
                    bool_696 = esi > 0x1;
                    if (esi == 0x1) {
                            edx = 0x0;
                            bool_659 = ecx < 0x0;
                            bool_391 = ecx > 0x0;
                            if (ecx == 0x0) {
                                    bool_1741 = eax[0x14833a] < esi;
                                    bool_1720 = eax[0x14833a] > esi;
                                    if (eax[0x14833a] == esi) {
                                            edx = 0x0;
                                            bool_1812 = eax[0x14833b] > 0x0;
                                            bool_701 = eax[0x14833b] != 0x0;
                                            bool_458 = eax[0x14833b] < 0x0;
                                            if (!bool_701) {
                                                    ebx = eax[0x14d73a];
                                                    ebx = ebx | eax[0x14d73b];
                                                    bool_1080 = ebx > 0x0;
                                                    bool_999 = ebx < 0x0;
                                                    if (ebx == 0x0) {
                                                            eax[0x17ba3a] = esi;
                                                            eax[0x17ba3b] = 0x0;
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            if (!bool_999) {
                                                                    if (!bool_1080) {
                                                                            if (esi > edx) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_458) {
                                                            if (!bool_1812) {
                                                                    if (esi > edx) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_1741) {
                                                    if (!bool_1720) {
                                                            edx = 0x0;
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = 0x0;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_659) {
                                            if (!bool_391) {
                                                    if (esi > 0x0) {
                                                            if (eax[0x14833a] == 0x1) {
                                                                    edx = 0x0;
                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = 0x0;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            if (!bool_717) {
                                    if (!bool_696) {
                                            if (esi > 0x0) {
                                                    if (eax[0x14833a] == 0x1) {
                                                            edx = 0x0;
                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = edx;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if (eax[0x14833a] == 0x1) {
                                                    edx = 0x0;
                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                            eax[0x17ba3a] = 0x2;
                                                            eax[0x17ba3b] = edx;
                                                    }
                                            }
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
    }
    else {
            ecx = decomp_var_b8;
            eax = ecx[0x2];
            edi = edi + 0x1;
            esi = decomp_var_9c + 0x24;
            decomp_var_9c = esi;
            if (edi < eax[0x900]) {
                    continue;
            }
            break;
    }
    goto loc_44a798;

loc_44abb0:
    eax = ebx[0x2];
    edx = eax[0x915];
    eax = eax + 0x2450;
    decomp_var_4 = edx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi != decomp_var_4) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x6] != decomp_var_b4) {
                    sub_401390();
                    esi = decomp_var_94;
                    edi = decomp_var_98;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
            }
            esp = esp - 0x4;
            decomp_var_cc = esi + 0x10;
            eax = sub_41c1e0(decomp_var_cc);
            edx = eax[0x1];
            ecx = (decomp_var_b4 << 0x8) + esi[0x4];
            bool_2113 = edx < *(ecx * 0x8 + 0x55b0ec);
            if (edx > *(ecx * 0x8 + 0x55b0ec)) {
                    sub_401390();
                    esi = decomp_var_94;
                    edi = decomp_var_98;
                    continue;
            }
            if (!bool_2113) {
                    if (*eax < *(ecx * 0x8 + 0x55b0e8)) {
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            esi = esi[0x4];
                            *(esi * 0x8 + 0x5b98e8) = 0x0;
                            *(esi * 0x8 + 0x5b98ec) = 0x0;
                            sub_401390();
                            esi = decomp_var_94;
                            edi = decomp_var_98;
                            continue;
                    }
                    sub_401390();
                    esi = decomp_var_94;
                    edi = decomp_var_98;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esi = esi[0x4];
            *(esi * 0x8 + 0x5b98e8) = 0x0;
            *(esi * 0x8 + 0x5b98ec) = 0x0;
            sub_401390();
            esi = decomp_var_94;
            edi = decomp_var_98;
            continue;
    }
    break;

loc_44aa01:
    edx = decomp_var_90;
    if (*(int8_t *)(edx + eax + 0x3) == 0x0) goto loc_44ab65;
    goto loc_44aa10;

.l41:
    bool_542 = esi < 0x1;
    bool_479 = esi > 0x1;
    if (esi != 0x1) goto .l43;
    goto loc_44a714;

loc_44a6e1:
    if (!bool_195) {
            if (esi > 0x0) {
                    if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                            if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                                    eax[0x17ba3a] = 0x1;
                                    eax[0x17ba3b] = 0x0;
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    bool_500 = esi < 0x1;
                                    bool_474 = esi > 0x1;
                                    if (esi == 0x1) {
                                            edx = 0x0;
                                            bool_1897 = ecx < 0x0;
                                            bool_1651 = ecx > 0x0;
                                            if (ecx == 0x0) {
                                                    bool_1487 = eax[0x14833a] < esi;
                                                    bool_1466 = eax[0x14833a] > esi;
                                                    if (eax[0x14833a] == esi) {
                                                            bool_1902 = eax[0x14833b] < 0x0;
                                                            bool_1567 = eax[0x14833b] > 0x0;
                                                            if (eax[0x14833b] == 0x0) {
                                                                    ebx = eax[0x14d73a];
                                                                    ebx = ebx | eax[0x14d73b];
                                                                    bool_1909 = ebx < 0x0;
                                                                    bool_1713 = ebx > 0x0;
                                                                    if (ebx == 0x0) {
                                                                            eax[0x17ba3a] = esi;
                                                                            eax[0x17ba3b] = 0x0;
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            if (!bool_1909) {
                                                                                    if (!bool_1713) {
                                                                                            edx = 0x0;
                                                                                            if (esi > 0x0) {
                                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                                    eax[0x17ba3b] = edx;
                                                                                                            }
                                                                                                    }
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                            else {
                                                                                                    ecx = decomp_var_b8;
                                                                                                    eax = ecx[0x2];
                                                                                                    edi = edi + 0x1;
                                                                                                    esi = decomp_var_9c + 0x24;
                                                                                                    decomp_var_9c = esi;
                                                                                                    if (edi < eax[0x900]) {
                                                                                                            continue;
                                                                                                    }
                                                                                                    break;
                                                                                            }
                                                                                    }
                                                                                    else {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                            }
                                                            else {
                                                                    if (!bool_1902) {
                                                                            if (!bool_1567) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1487) {
                                                                    if (!bool_1466) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_1897) {
                                                            if (!bool_1651) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_500) {
                                                    if (!bool_474) {
                                                            edx = 0x0;
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1) {
                                                                    edx = 0x0;
                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                    }
                    else {
                            bool_282 = esi < 0x1;
                            bool_254 = esi > 0x1;
                            if (esi == 0x1) {
                                    bool_1214 = ecx < 0x0;
                                    bool_952 = ecx > 0x0;
                                    if (ecx == 0x0) {
                                            bool_669 = eax[0x14833a] < esi;
                                            bool_642 = eax[0x14833a] > esi;
                                            if (eax[0x14833a] == esi) {
                                                    edx = 0x0;
                                                    bool_1361 = eax[0x14833b] != 0x0;
                                                    bool_1155 = eax[0x14833b] < 0x0;
                                                    bool_739 = eax[0x14833b] > 0x0;
                                                    if (!bool_1361) {
                                                            ebx = eax[0x14d73a];
                                                            ebx = ebx | eax[0x14d73b];
                                                            bool_1595 = ebx > 0x0;
                                                            bool_351 = ebx < 0x0;
                                                            if (ebx == 0x0) {
                                                                    eax[0x17ba3a] = esi;
                                                                    eax[0x17ba3b] = 0x0;
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    if (!bool_351) {
                                                                            if (!bool_1595) {
                                                                                    if (esi > 0x0) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_1155) {
                                                                    if (!bool_739) {
                                                                            if (esi > edx) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_669) {
                                                            if (!bool_642) {
                                                                    edx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1) {
                                                                            edx = 0x0;
                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_1214) {
                                                    if (!bool_952) {
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1) {
                                                                    edx = 0x0;
                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_282) {
                                            if (!bool_254) {
                                                    edx = 0x0;
                                                    if (esi > 0x0) {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = 0x0;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
            }
            else {
                    bool_685 = esi < 0x1;
                    bool_440 = esi > 0x1;
                    if (esi == 0x1) {
                            edx = 0x0;
                            bool_1877 = ecx > 0x0;
                            bool_381 = ecx < 0x0;
                            if (ecx == 0x0) {
                                    bool_1257 = eax[0x14833a] != esi;
                                    bool_899 = eax[0x14833a] < esi;
                                    bool_882 = eax[0x14833a] > esi;
                                    if (!bool_1257) {
                                            bool_1581 = eax[0x14833b] != edx;
                                            bool_1346 = eax[0x14833b] < edx;
                                            bool_962 = eax[0x14833b] > edx;
                                            if (!bool_1581) {
                                                    ebx = eax[0x14d73a];
                                                    ebx = ebx | eax[0x14d73b];
                                                    bool_804 = ebx > 0x0;
                                                    bool_727 = ebx < 0x0;
                                                    if (ebx == 0x0) {
                                                            eax[0x17ba3a] = esi;
                                                            eax[0x17ba3b] = edx;
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            if (!bool_727) {
                                                                    if (!bool_804) {
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = 0x0;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_1346) {
                                                            if (!bool_962) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_899) {
                                                    if (!bool_882) {
                                                            if (esi > edx) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_381) {
                                            if (!bool_1877) {
                                                    if (esi > 0x0) {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = 0x0;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = 0x0;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            if (!bool_685) {
                                    if (!bool_440) {
                                            edx = 0x0;
                                            if (esi > 0x0) {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = edx;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if (eax[0x14833a] == 0x1) {
                                                    edx = 0x0;
                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                            eax[0x17ba3a] = 0x2;
                                                            eax[0x17ba3b] = edx;
                                                    }
                                            }
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
    }
    else {
            if ((eax[0x14833a] | eax[0x14833b]) == 0x0) {
                    if ((eax[0x14ad3a] | eax[0x14ad3b]) == 0x0) {
                            eax[0x17ba3a] = 0x1;
                            eax[0x17ba3b] = 0x0;
                            ecx = decomp_var_b8;
                            eax = ecx[0x2];
                            edi = edi + 0x1;
                            esi = decomp_var_9c + 0x24;
                            decomp_var_9c = esi;
                            if (edi < eax[0x900]) {
                                    continue;
                            }
                            break;
                    }
                    else {
                            bool_417 = esi < 0x1;
                            bool_392 = esi > 0x1;
                            if (esi == 0x1) {
                                    bool_1832 = ecx < 0x0;
                                    bool_1556 = ecx > 0x0;
                                    if (ecx == 0x0) {
                                            bool_1504 = eax[0x14833a] != esi;
                                            bool_344 = eax[0x14833a] < esi;
                                            bool_316 = eax[0x14833a] > esi;
                                            if (!bool_1504) {
                                                    edx = 0x0;
                                                    bool_1084 = eax[0x14833b] != 0x0;
                                                    bool_846 = eax[0x14833b] < 0x0;
                                                    bool_418 = eax[0x14833b] > 0x0;
                                                    if (!bool_1084) {
                                                            ebx = eax[0x14d73a];
                                                            ebx = ebx | eax[0x14d73b];
                                                            bool_1564 = ebx > 0x0;
                                                            bool_996 = ebx < 0x0;
                                                            if (ebx == 0x0) {
                                                                    eax[0x17ba3a] = esi;
                                                                    eax[0x17ba3b] = edx;
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    if (!bool_996) {
                                                                            if (!bool_1564) {
                                                                                    if (esi > edx) {
                                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                            eax[0x17ba3a] = 0x2;
                                                                                                            eax[0x17ba3b] = 0x0;
                                                                                                    }
                                                                                            }
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                    else {
                                                                                            ecx = decomp_var_b8;
                                                                                            eax = ecx[0x2];
                                                                                            edi = edi + 0x1;
                                                                                            esi = decomp_var_9c + 0x24;
                                                                                            decomp_var_9c = esi;
                                                                                            if (edi < eax[0x900]) {
                                                                                                    continue;
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                            }
                                                                            else {
                                                                                    if (eax[0x14833a] == 0x1) {
                                                                                            edx = 0x0;
                                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                    }
                                                    else {
                                                            if (!bool_846) {
                                                                    if (!bool_418) {
                                                                            if (esi > edx) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_344) {
                                                            if (!bool_316) {
                                                                    edx = 0x0;
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = 0x0;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_1832) {
                                                    if (!bool_1556) {
                                                            if (esi > 0x0) {
                                                                    if (eax[0x14833a] == 0x1) {
                                                                            edx = 0x0;
                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = 0x0;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_417) {
                                            if (!bool_392) {
                                                    edx = 0x0;
                                                    if (esi > 0x0) {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = 0x0;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (eax[0x14833a] == 0x1) {
                                                            edx = 0x0;
                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = edx;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
            }
            else {
                    bool_889 = esi < 0x1;
                    bool_869 = esi > 0x1;
                    if (esi == 0x1) {
                            edx = 0x0;
                            bool_1871 = ecx > 0x0;
                            bool_373 = ecx < 0x0;
                            if (ecx == 0x0) {
                                    bool_1435 = eax[0x14833a] < esi;
                                    bool_1412 = eax[0x14833a] > esi;
                                    if (eax[0x14833a] == esi) {
                                            bool_1922 = eax[0x14833b] < 0x0;
                                            bool_1508 = eax[0x14833b] > 0x0;
                                            if (eax[0x14833b] == 0x0) {
                                                    ebx = eax[0x14d73a];
                                                    ebx = ebx | eax[0x14d73b];
                                                    bool_1296 = ebx < 0x0;
                                                    bool_795 = ebx > 0x0;
                                                    if (ebx == 0x0) {
                                                            eax[0x17ba3a] = esi;
                                                            eax[0x17ba3b] = 0x0;
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            if (!bool_1296) {
                                                                    if (!bool_795) {
                                                                            edx = 0x0;
                                                                            if (esi > 0x0) {
                                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                                    eax[0x17ba3a] = 0x2;
                                                                                                    eax[0x17ba3b] = edx;
                                                                                            }
                                                                                    }
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                            else {
                                                                                    ecx = decomp_var_b8;
                                                                                    eax = ecx[0x2];
                                                                                    edi = edi + 0x1;
                                                                                    esi = decomp_var_9c + 0x24;
                                                                                    decomp_var_9c = esi;
                                                                                    if (edi < eax[0x900]) {
                                                                                            continue;
                                                                                    }
                                                                                    break;
                                                                            }
                                                                    }
                                                                    else {
                                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = 0x0;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                            }
                                            else {
                                                    if (!bool_1922) {
                                                            if (!bool_1508) {
                                                                    if (esi > 0x0) {
                                                                            if (eax[0x14833a] == 0x1) {
                                                                                    edx = 0x0;
                                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                            eax[0x17ba3a] = 0x2;
                                                                                            eax[0x17ba3b] = edx;
                                                                                    }
                                                                            }
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                                    else {
                                                                            ecx = decomp_var_b8;
                                                                            eax = ecx[0x2];
                                                                            edi = edi + 0x1;
                                                                            esi = decomp_var_9c + 0x24;
                                                                            decomp_var_9c = esi;
                                                                            if (edi < eax[0x900]) {
                                                                                    continue;
                                                                            }
                                                                            break;
                                                                    }
                                                            }
                                                            else {
                                                                    if (eax[0x14833a] == 0x1) {
                                                                            edx = 0x0;
                                                                            if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                    }
                                    else {
                                            if (!bool_1435) {
                                                    if (!bool_1412) {
                                                            if (esi > edx) {
                                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                                    eax[0x17ba3a] = 0x2;
                                                                                    eax[0x17ba3b] = edx;
                                                                            }
                                                                    }
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                            else {
                                                                    ecx = decomp_var_b8;
                                                                    eax = ecx[0x2];
                                                                    edi = edi + 0x1;
                                                                    esi = decomp_var_9c + 0x24;
                                                                    decomp_var_9c = esi;
                                                                    if (edi < eax[0x900]) {
                                                                            continue;
                                                                    }
                                                                    break;
                                                            }
                                                    }
                                                    else {
                                                            if (eax[0x14833a] == 0x1) {
                                                                    edx = 0x0;
                                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                            }
                            else {
                                    if (!bool_373) {
                                            if (!bool_1871) {
                                                    if (esi > 0x0) {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = 0x0;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = 0x0;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            if (!bool_889) {
                                    if (!bool_869) {
                                            edx = 0x0;
                                            if (esi > 0x0) {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = edx;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if (eax[0x14833a] == 0x1) {
                                                    edx = 0x0;
                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                            eax[0x17ba3a] = 0x2;
                                                            eax[0x17ba3b] = edx;
                                                    }
                                            }
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
    }
    goto loc_44a798;
    edi = ebx[0x2];
    esi = *edi[0x915];
    edi = edi + 0x2450;
    decomp_var_98 = edi;
    decomp_var_94 = esi;
    goto loc_44ac92;

loc_44ab65:
    eax = decomp_var_b8[0x2];
    decomp_var_90 = decomp_var_90 + 0x24;
    decomp_var_b0 = decomp_var_b0 + 0xc;
    bool_12 = decomp_var_84 + 0x1 < eax[0x900];
    decomp_var_84 = decomp_var_84 + 0x1;
    if (bool_12) {
            continue;
    }
    break;

loc_44aa10:
    eax = *(int16_t *)(edx + eax + 0x20);
    bool_11 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_11) {
            eax = 0x14;
    }
    if (eax == decomp_var_b4 || *((decomp_var_b4 * 0x15 + eax) * 0x4 + 0x634e90) >= 0xa) goto loc_44ab65;
    goto loc_44aa45;

.l43:
    if (bool_542) goto .l52;
    goto loc_44a742;

loc_44a714:
    bool_1874 = ecx > 0x0;
    bool_379 = ecx < 0x0;
    if (ecx == 0x0) {
            bool_1381 = eax[0x14833a] != esi;
            bool_1105 = eax[0x14833a] < esi;
            bool_1086 = eax[0x14833a] > esi;
            if (!bool_1381) {
                    bool_1591 = eax[0x14833b] > 0x0;
                    bool_477 = eax[0x14833b] != 0x0;
                    bool_227 = eax[0x14833b] < 0x0;
                    if (!bool_477) {
                            ebx = eax[0x14d73a];
                            ebx = ebx | eax[0x14d73b];
                            bool_1301 = ebx < 0x0;
                            bool_797 = ebx > 0x0;
                            if (ebx == 0x0) {
                                    eax[0x17ba3a] = esi;
                                    eax[0x17ba3b] = 0x0;
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    if (!bool_1301) {
                                            if (!bool_797) {
                                                    edx = 0x0;
                                                    if (esi > 0x0) {
                                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                            eax[0x17ba3a] = 0x2;
                                                                            eax[0x17ba3b] = edx;
                                                                    }
                                                            }
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                                    else {
                                                            ecx = decomp_var_b8;
                                                            eax = ecx[0x2];
                                                            edi = edi + 0x1;
                                                            esi = decomp_var_9c + 0x24;
                                                            decomp_var_9c = esi;
                                                            if (edi < eax[0x900]) {
                                                                    continue;
                                                            }
                                                            break;
                                                    }
                                            }
                                            else {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = 0x0;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                    }
                    else {
                            if (!bool_227) {
                                    if (!bool_1591) {
                                            if (esi > 0x0) {
                                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                                    eax[0x17ba3a] = 0x2;
                                                                    eax[0x17ba3b] = 0x0;
                                                            }
                                                    }
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                            else {
                                                    ecx = decomp_var_b8;
                                                    eax = ecx[0x2];
                                                    edi = edi + 0x1;
                                                    esi = decomp_var_9c + 0x24;
                                                    decomp_var_9c = esi;
                                                    if (edi < eax[0x900]) {
                                                            continue;
                                                    }
                                                    break;
                                            }
                                    }
                                    else {
                                            if (eax[0x14833a] == 0x1) {
                                                    edx = 0x0;
                                                    if (eax[0x14833b] == 0x0 && (eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                            eax[0x17ba3a] = 0x2;
                                                            eax[0x17ba3b] = edx;
                                                    }
                                            }
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
            }
            else {
                    if (!bool_1105) {
                            if (!bool_1086) {
                                    edx = 0x0;
                                    if (esi > 0x0) {
                                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                            eax[0x17ba3a] = 0x2;
                                                            eax[0x17ba3b] = edx;
                                                    }
                                            }
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                                    else {
                                            ecx = decomp_var_b8;
                                            eax = ecx[0x2];
                                            edi = edi + 0x1;
                                            esi = decomp_var_9c + 0x24;
                                            decomp_var_9c = esi;
                                            if (edi < eax[0x900]) {
                                                    continue;
                                            }
                                            break;
                                    }
                            }
                            else {
                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                    eax[0x17ba3a] = 0x2;
                                                    eax[0x17ba3b] = 0x0;
                                            }
                                    }
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            ecx = decomp_var_b8;
                            eax = ecx[0x2];
                            edi = edi + 0x1;
                            esi = decomp_var_9c + 0x24;
                            decomp_var_9c = esi;
                            if (edi < eax[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
    }
    else {
            if (!bool_379) {
                    if (!bool_1874) {
                            if (esi > 0x0) {
                                    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                                    eax[0x17ba3a] = 0x2;
                                                    eax[0x17ba3b] = 0x0;
                                            }
                                    }
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                            else {
                                    ecx = decomp_var_b8;
                                    eax = ecx[0x2];
                                    edi = edi + 0x1;
                                    esi = decomp_var_9c + 0x24;
                                    decomp_var_9c = esi;
                                    if (edi < eax[0x900]) {
                                            continue;
                                    }
                                    break;
                            }
                    }
                    else {
                            if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
                                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                                            eax[0x17ba3a] = 0x2;
                                            eax[0x17ba3b] = 0x0;
                                    }
                            }
                            ecx = decomp_var_b8;
                            eax = ecx[0x2];
                            edi = edi + 0x1;
                            esi = decomp_var_9c + 0x24;
                            decomp_var_9c = esi;
                            if (edi < eax[0x900]) {
                                    continue;
                            }
                            break;
                    }
            }
            else {
                    ecx = decomp_var_b8;
                    eax = ecx[0x2];
                    edi = edi + 0x1;
                    esi = decomp_var_9c + 0x24;
                    decomp_var_9c = esi;
                    if (edi < eax[0x900]) {
                            continue;
                    }
                    break;
            }
    }
    goto loc_44a798;

loc_44ac92:
    eax = ebx[0x2];
    edx = eax[0x915];
    eax = eax + 0x2450;
    arg_18 = edx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == arg_18) goto .l105;
    goto loc_44acc1;

loc_44aa45:
    eax = decomp_var_b0;
    edi = *eax[0x1];
    esi = eax;
    decomp_var_9c = 0x0;
    decomp_var_8c = esi;
    decomp_var_88 = edi;
    goto loc_44aa60;

.l52:
    ecx = decomp_var_b8;
    eax = ecx[0x2];
    edi = edi + 0x1;
    esi = decomp_var_9c + 0x24;
    decomp_var_9c = esi;
    if (edi < eax[0x900]) {
            continue;
    }
    break;

loc_44a742:
    if (bool_479) goto loc_44a748;
    goto loc_44a744;

.l105:
    break;

loc_44acc1:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != decomp_var_b4) {
            sub_401390();
            esi = decomp_var_94;
            edi = decomp_var_98;
            ebx = decomp_var_b8;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_cc = esi + 0x14;
    eax = sub_4075b0(decomp_var_cc, decomp_var_c8);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_b0 = eax;
    decomp_var_ac = ebx;
    decomp_var_a8 = esi;
    goto loc_44ad22;

loc_44aa60:
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = (decomp_var_b4 << 0x8) + edi[0x3];
            if (*(eax * 0x8 + 0x5ee8e8) == 0xfffffff6 && *(eax * 0x8 + 0x5ee8ec) == 0xffffffff) {
                    decomp_var_9c = decomp_var_9c + 0x1;
            }
            sub_401520();
            edi = decomp_var_88;
            esi = decomp_var_8c;
            eax = decomp_var_b0;
            continue;
    }
    break;

loc_44a748:
    if (eax[0x14833a] == 0x1 && eax[0x14833b] == 0x0) {
            if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                    eax[0x17ba3a] = 0x2;
                    eax[0x17ba3b] = 0x0;
            }
    }
    goto loc_44a777;

loc_44a744:
    edx = 0x0;
    if (esi > 0x0) {
            if (eax[0x14833a] == 0x1 && eax[0x14833b] == edx) {
                    if ((eax[0x14d73a] | eax[0x14d73b]) == 0x0) {
                            eax[0x17ba3a] = 0x2;
                            eax[0x17ba3b] = edx;
                    }
            }
            ecx = decomp_var_b8;
            eax = ecx[0x2];
            edi = edi + 0x1;
            esi = decomp_var_9c + 0x24;
            decomp_var_9c = esi;
            if (edi < eax[0x900]) {
                    continue;
            }
            break;
    }
    else {
            ecx = decomp_var_b8;
            eax = ecx[0x2];
            edi = edi + 0x1;
            esi = decomp_var_9c + 0x24;
            decomp_var_9c = esi;
            if (edi < eax[0x900]) {
                    continue;
            }
            break;
    }
    goto loc_44a798;
    sub_4460a0(decomp_var_c8, decomp_var_c4, decomp_var_c0);
    edi = ebx[0x2];
    esi = *edi[0x915];
    edi = edi + 0x2450;
    decomp_var_98 = edi;
    decomp_var_94 = esi;
    goto loc_44ae60;

loc_44ad22:
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
            edi = esi + 0xc;
            if ((*(eax * 0x8 + 0x5b98e8) | *(eax * 0x8 + 0x5b98ec)) == 0x0) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = *edi;
                    esi = decomp_var_b4 << 0x8;
                    eax = eax + esi;
                    if (*(eax * 0x8 + 0x520ce8) == 0x1 && *(eax * 0x8 + 0x520cec) == 0x0) {
                            if (decomp_var_a8 == ebx[0x1]) {
                                    sub_47a948();
                            }
                            if (decomp_var_a8 == ebx[0x1]) {
                                    sub_47a948();
                            }
                            esp = esp - 0x4;
                            decomp_var_cc = edi;
                            eax = sub_41c1e0(decomp_var_cc);
                            ecx = *edi;
                            ecx = ecx + esi;
                            if (*eax == *(ecx * 0x8 + 0x55b0e8) && eax[0x1] == *(ecx * 0x8 + 0x55b0ec)) {
                                    if (decomp_var_a8 == ebx[0x1]) {
                                            sub_47a948();
                                    }
                                    edi = *edi;
                                    *(edi * 0x8 + 0x5b98e8) = 0x1;
                                    *(edi * 0x8 + 0x5b98ec) = 0x0;
                            }
                    }
            }
            sub_40f400();
            esi = decomp_var_a8;
            ebx = decomp_var_ac;
            eax = decomp_var_b0;
            continue;
    }
    break;
    eax = decomp_var_b0;
    edi = *eax[0x1];
    ebx = eax;
    decomp_var_8c = ebx;
    decomp_var_88 = edi;
    goto loc_44aad4;

loc_44ae60:
    eax = ebx[0x2];
    ecx = eax[0x915];
    eax = eax + 0x2450;
    arg_8 = ecx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == arg_8) goto .l99;
    goto loc_44ae8f;
    sub_401390();
    esi = decomp_var_94;
    edi = decomp_var_98;
    ebx = decomp_var_b8;
    continue;

loc_44aad4:
    esi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != esi) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            esi = decomp_var_b4 << 0x8;
            eax = eax + esi;
            if (*(eax * 0x8 + 0x5ee8e8) != 0xfffffff6) {
                    sub_401520();
                    edi = decomp_var_88;
                    ebx = decomp_var_8c;
                    eax = decomp_var_b0;
                    continue;
            }
            if (*(eax * 0x8 + 0x5ee8ec) == 0xffffffff && decomp_var_9c > 0x1) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = edi[0x3];
                    *((eax + esi) * 0x8 + 0x5ee8e8) = 0x1;
                    *((eax + esi) * 0x8 + 0x5ee8ec) = 0x0;
            }
            sub_401520();
            edi = decomp_var_88;
            ebx = decomp_var_8c;
            eax = decomp_var_b0;
            continue;
    }
    break;

.l99:
    break;

loc_44ae8f:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != decomp_var_b4) {
            sub_401390();
            esi = decomp_var_94;
            edi = decomp_var_98;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_cc = esi + 0x14;
    eax = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = eax;
    decomp_var_b0 = eax;
    decomp_var_ac = edi;
    decomp_var_a8 = *eax[0x1];
    &decomp_var_c8 = &decomp_var_c8;
    goto loc_44aef0;
    edi = ebx[0x2];
    esi = *edi[0x915];
    edi = edi + 0x2450;
    decomp_var_98 = edi;
    decomp_var_94 = esi;
    goto loc_44b0b0;

loc_44aef0:
    esi = eax[0x1];
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (decomp_var_a8 == esi) goto .l75;
    goto loc_44af0a;

loc_44b0b0:
    eax = ebx[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == ebx) goto .l93;
    goto loc_44b0d3;

.l75:
    break;

loc_44af0a:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    ecx = decomp_var_a8;
    eax = ecx[0x3];
    bool_119 = *(eax * 0x8 + 0x4d2e14) < 0x0;
    bool_109 = *(eax * 0x8 + 0x4d2e14) > 0x0;
    esi = ecx + 0xc;
    if (bool_119) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (bool_109) goto loc_44af49;
    goto loc_44af3b;

.l93:
    break;

loc_44b0d3:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    if (esi[0x6] != decomp_var_b4) {
            sub_401390();
            esi = decomp_var_94;
            edi = decomp_var_98;
            ebx = decomp_var_b8;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_cc = esi + 0x14;
    eax = sub_4075b0(decomp_var_cc, decomp_var_c8);
    esi = *eax[0x1];
    ebx = eax;
    goto loc_44b134;
    sub_401390();
    esi = decomp_var_94;
    edi = decomp_var_98;
    continue;

loc_44af49:
    if (ecx == edi[0x1]) {
            sub_47a948();
    }
    ebx = decomp_var_b4;
    ecx = *esi;
    decomp_var_1c = ebx & 0x80000000 ? 0xffffffff : 0x0;
    if (*(ecx * 0x8 + 0x4d2e10) != ebx) goto .l15;
    goto .l14;

loc_44af3b:
    if (*(eax * 0x8 + 0x4d2e10) < 0x0) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (ecx == edi[0x1]) {
            sub_47a948();
    }
    ebx = decomp_var_b4;
    ecx = *esi;
    decomp_var_1c = ebx & 0x80000000 ? 0xffffffff : 0x0;
    if (*(ecx * 0x8 + 0x4d2e10) != ebx) goto loc_44af82;
    goto loc_44af6e;
    ebx = decomp_var_b8;
    decomp_var_9c = 0x3;
    goto loc_44b350;

loc_44b134:
    edi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi == edi) goto .l69;
    goto loc_44b14c;

.l15:
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    eax = *esi;
    eax = eax + (ebx << 0x8);
    bool_122 = *(eax * 0x8 + 0x58f8ec) > 0x0;
    decomp_var_90 = ebx << 0x8;
    if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (bool_122) goto loc_44afbb;
    goto .l16;

.l14:
    if (*(ecx * 0x8 + 0x4d2e14) == decomp_var_1c) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    eax = *esi;
    eax = eax + (ebx << 0x8);
    bool_121 = *(eax * 0x8 + 0x58f8ec) > 0x0;
    decomp_var_90 = ebx << 0x8;
    if (*(eax * 0x8 + 0x58f8ec) < 0x0) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (bool_121) goto .l9;
    goto loc_44afad;

loc_44af82:
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    eax = *esi;
    eax = eax + (ebx << 0x8);
    bool_100 = *(eax * 0x8 + 0x58f8ec) < 0x0;
    bool_93 = *(eax * 0x8 + 0x58f8ec) > 0x0;
    decomp_var_90 = ebx << 0x8;
    if (bool_100) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (bool_93) goto .l18;
    goto .l17;

loc_44af6e:
    if (*(ecx * 0x8 + 0x4d2e14) == decomp_var_1c) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    eax = *esi;
    eax = eax + (ebx << 0x8);
    bool_112 = *(eax * 0x8 + 0x58f8ec) < 0x0;
    bool_95 = *(eax * 0x8 + 0x58f8ec) > 0x0;
    decomp_var_90 = ebx << 0x8;
    if (bool_112) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (bool_95) goto .l13;
    goto .l4;

loc_44b350:
    eax = ebx[0x2];
    esi = *eax[0x915];
    edi = eax + 0x2450;
    decomp_var_98 = edi;
    decomp_var_94 = esi;
    goto loc_44b370;

.l69:
    break;

loc_44b14c:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    edi = decomp_var_b4 << 0x8;
    *((eax + edi) * 0x8 + 0x5c48e8) = 0x1;
    *((eax + edi) * 0x8 + 0x5c48ec) = 0x0;
    if (esi == ebx[0x1]) {
            sub_47a948();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_cc = esi + 0x10;
    eax = sub_4075b0(decomp_var_cc, decomp_var_c8);
    esi = *eax[0x1];
    ebx = eax;
    decomp_var_9c = eax;
    decomp_var_78 = ebx;
    decomp_var_74 = esi;
    goto loc_44b1d0;

loc_44afbb:
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto .l19;

.l16:
    if (*(eax * 0x8 + 0x58f8e8) <= 0x0) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto .l23;

.l9:
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto .l21;

loc_44afad:
    if (*(eax * 0x8 + 0x58f8e8) <= 0x0) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto .l20;

.l18:
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto .l25;

.l17:
    if (*(eax * 0x8 + 0x58f8e8) <= 0x0) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto .l24;

.l13:
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto .l22;

.l4:
    if (*(eax * 0x8 + 0x58f8e8) <= 0x0) {
            sub_40f400();
            edi = decomp_var_ac;
            eax = decomp_var_b0;
            ebx = decomp_var_b8;
            continue;
    }
    if (decomp_var_a8 == edi[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    decomp_var_cc = sub_407720(esi) + 0x4;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_78 = esi;
    decomp_var_74 = edi;
    goto loc_44b002;

loc_44b370:
    eax = ebx[0x2];
    edx = eax[0x915];
    eax = eax + 0x2450;
    arg_10 = edx;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (esi == arg_10) goto .l87;
    goto loc_44b39f;
    sub_401390();
    esi = decomp_var_94;
    edi = decomp_var_98;
    ebx = decomp_var_b8;
    continue;

loc_44b1d0:
    arg_14 = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (esi == arg_14) goto .l57;
    goto loc_44b1f4;

.l19:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

.l23:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

.l21:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

.l20:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

.l25:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

.l24:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

.l22:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

loc_44b002:
    decomp_var_c = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != decomp_var_c) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5cf0e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5cf0ec) = 0x0;
            sub_40f400();
            edi = decomp_var_74;
            esi = decomp_var_78;
            continue;
    }
    break;

.l87:
    break;

loc_44b39f:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x4];
    eax = eax + (decomp_var_b4 << 0x8);
    decomp_var_90 = decomp_var_b4 << 0x8;
    if (*(eax * 0x8 + 0x5c48e8) != 0x1) {
            sub_401390();
            esi = decomp_var_94;
            edi = decomp_var_98;
            ebx = decomp_var_b8;
            continue;
    }
    if (*(eax * 0x8 + 0x5c48ec) != 0x0) {
            sub_401390();
            esi = decomp_var_94;
            edi = decomp_var_98;
            ebx = decomp_var_b8;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    decomp_var_cc = esi + 0x14;
    ebx = sub_4075b0(decomp_var_cc, decomp_var_c8);
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_ac = esi;
    decomp_var_a8 = edi;
    goto loc_44b420;

.l57:
    break;

loc_44b1f4:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    if (*(int8_t *)(decomp_var_a4[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) {
            sub_40f400();
            esi = decomp_var_60;
            ebx = decomp_var_64;
            eax = decomp_var_88;
            edi = decomp_var_7c;
            continue;
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    *((eax + edi) * 0x8 + 0x5ba0e8) = 0x1;
    *((eax + edi) * 0x8 + 0x5ba0ec) = 0x0;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    edi = decomp_var_a4 + (eax + eax * 0x2) * 0x4 + 0x2a1c;
    decomp_var_78 = edi;
    decomp_var_74 = **(decomp_var_a4 + (eax + eax * 0x2) * 0x4 + 0x2a20);
    goto loc_44b270;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    edi = decomp_var_ac;
    eax = decomp_var_b0;
    ebx = decomp_var_b8;
    continue;
    decomp_var_9c = decomp_var_9c - 0x1;
    if (decomp_var_9c != 0x0) {
            continue;
    }
    break;

loc_44b420:
    arg_20 = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (edi != arg_20) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            *((eax + decomp_var_90) * 0x8 + 0x5c48e8) = 0x1;
            *((eax + decomp_var_90) * 0x8 + 0x5c48ec) = 0x0;
            sub_40f400();
            edi = decomp_var_a8;
            esi = decomp_var_ac;
            continue;
    }
    break;
    sub_40f400();
    esi = decomp_var_94;
    ebx = decomp_var_98;
    eax = decomp_var_9c;
    continue;

loc_44b270:
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    ebx = *(decomp_var_a4 + (eax + eax * 0x2) * 0x4 + 0x2a20);
    eax = decomp_var_a4 + (eax + eax * 0x2) * 0x4 + 0x2a1c;
    if (edi == 0x0 || edi != eax) {
            sub_47a948();
    }
    if (decomp_var_74 != ebx) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (decomp_var_74 == edi[0x1]) {
                    sub_47a948();
            }
            eax = decomp_var_74[0x3];
            *((eax + decomp_var_7c) * 0x8 + 0x5ba0e8) = 0x1;
            *((eax + decomp_var_7c) * 0x8 + 0x5ba0ec) = 0x0;
            sub_401520();
            edi = decomp_var_78;
            ebx = decomp_var_64;
            continue;
    }
    break;
    eax = ebx[0x2];
    decomp_var_84 = 0x0;
    if (eax[0x900] <= 0x0) goto loc_44b734;
    goto loc_44b4c0;
    sub_401390();
    esi = decomp_var_94;
    edi = decomp_var_98;
    ebx = decomp_var_b8;
    continue;
    sub_40f400();
    esi = decomp_var_60;
    ebx = decomp_var_64;
    eax = decomp_var_88;
    edi = decomp_var_7c;
    continue;

loc_44b734:
    edx = decomp_var_b8[0x2];
    bool_6 = decomp_var_b4 + 0x1 < edx[0x901];
    decomp_var_b4 = decomp_var_b4 + 0x1;
    if (bool_6) {
            eax = decomp_var_b4;
            continue;
    }
    temp_1 = 0x1;
    break;

loc_44b4c0:
    edx = 0x0;
    ebx = decomp_var_b8 + 0x2a1c;
    decomp_var_9c = 0x0;
    goto loc_44b4d4;

loc_44b4d4:
    if (*(int8_t *)(edx + eax + 0x3) == 0x0) goto .l40;
    goto loc_44b4df;

.l40:
    eax = decomp_var_b8[0x2];
    edx = edx + 0x24;
    ebx = ebx + 0xc;
    bool_1950 = decomp_var_84 + 0x1 < eax[0x900];
    decomp_var_84 = decomp_var_84 + 0x1;
    decomp_var_9c = edx;
    if (bool_1950) {
            continue;
    }
    break;

loc_44b4df:
    esi = decomp_var_b4;
    decomp_var_90 = esi << 0x8;
    ecx = (esi << 0x8) + decomp_var_84 + (esi << 0x8) + decomp_var_84 + (esi << 0x8) + decomp_var_84 + (esi << 0x8) + decomp_var_84 + (esi << 0x8) + decomp_var_84 + (esi << 0x8) + decomp_var_84 + (esi << 0x8) + decomp_var_84 + (esi << 0x8) + decomp_var_84;
    bool_1954 = ecx[0x163e3b] < 0x0;
    bool_1944 = ecx[0x163e3b] > 0x0;
    decomp_var_38 = ecx;
    if (bool_1954) goto .l38;
    goto loc_44b50c;

.l38:
    eax = decomp_var_b8[0x2];
    edx = edx + 0x24;
    ebx = ebx + 0xc;
    bool_1951 = decomp_var_84 + 0x1 < eax[0x900];
    decomp_var_84 = decomp_var_84 + 0x1;
    decomp_var_9c = edx;
    if (bool_1951) {
            continue;
    }
    break;

loc_44b50c:
    if (bool_1944) goto loc_44b51b;
    goto loc_44b50e;

loc_44b51b:
    eax = *(int16_t *)(edx + eax + 0x20);
    bool_1945 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_1945) {
            eax = 0x14;
    }
    if (eax == esi) goto .l31;
    goto .l30;

loc_44b50e:
    if (ecx[0x163e3a] <= 0x0) goto .l32;
    goto .l29;

.l31:
    eax = decomp_var_b8[0x2];
    edx = edx + 0x24;
    ebx = ebx + 0xc;
    bool_1955 = decomp_var_84 + 0x1 < eax[0x900];
    decomp_var_84 = decomp_var_84 + 0x1;
    decomp_var_9c = edx;
    if (bool_1955) {
            continue;
    }
    break;

.l30:
    esi = *ebx[0x1];
    edi = ebx;
    decomp_var_88 = esi;
    goto loc_44b544;

.l32:
    eax = decomp_var_b8[0x2];
    edx = edx + 0x24;
    ebx = ebx + 0xc;
    bool_1947 = decomp_var_84 + 0x1 < eax[0x900];
    decomp_var_84 = decomp_var_84 + 0x1;
    decomp_var_9c = edx;
    if (bool_1947) {
            continue;
    }
    break;

.l29:
    eax = *(int16_t *)(edx + eax + 0x20);
    bool_1949 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_1949) {
            eax = 0x14;
    }
    if (eax == esi) goto loc_44b708;
    goto loc_44b535;

loc_44b544:
    arg_30 = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi == arg_30) goto .l72;
    goto loc_44b568;

loc_44b708:
    eax = decomp_var_b8[0x2];
    edx = edx + 0x24;
    ebx = ebx + 0xc;
    bool_1946 = decomp_var_84 + 0x1 < eax[0x900];
    decomp_var_84 = decomp_var_84 + 0x1;
    decomp_var_9c = edx;
    if (bool_1946) {
            continue;
    }
    break;

loc_44b535:
    esi = *ebx[0x1];
    edi = ebx;
    decomp_var_88 = esi;
    goto .l55;

.l72:
    break;

loc_44b568:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    eax = eax + decomp_var_90;
    bool_1980 = *(eax * 0x8 + 0x520cec) > 0x0;
    if (*(eax * 0x8 + 0x520cec) < 0x0) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (bool_1980) goto loc_44b5a0;
    goto loc_44b592;

.l55:
    arg_30 = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (esi == arg_30) goto .l48;
    goto .l54;
    edx = decomp_var_9c;
    goto .l31;

loc_44b5a0:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    if (*(int8_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) goto loc_44b5f1;
    goto loc_44b5be;

loc_44b592:
    if (*(eax * 0x8 + 0x520ce8) <= 0x0) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    if (*(int8_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) goto .l37;
    goto .l34;

.l48:
    break;

.l54:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    eax = eax + decomp_var_90;
    bool_2031 = *(eax * 0x8 + 0x520cec) < 0x0;
    bool_2019 = *(eax * 0x8 + 0x520cec) > 0x0;
    if (bool_2031) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (bool_2019) goto .l51;
    goto .l56;

loc_44b5f1:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_1958 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_1958) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto .l44;

loc_44b5be:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    eax = *(int16_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
    bool_1971 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_1971) {
            eax = 0x14;
    }
    if (eax != decomp_var_b4) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_1962 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_1962) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto loc_44b640;

.l37:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_1963 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_1963) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto .l42;

.l34:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    eax = *(int16_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
    bool_1961 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_1961) {
            eax = 0x14;
    }
    if (eax != decomp_var_b4) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_1974 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_1974) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto .l45;
    edx = decomp_var_9c;
    goto loc_44b708;

.l51:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    if (*(int8_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) goto .l59;
    goto .l60;

.l56:
    if (*(eax * 0x8 + 0x520ce8) <= 0x0) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    if (*(int8_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x3) == 0x0) goto .l50;
    goto .l53;

.l44:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_2002 = edx < edi[0x15c03b];
            bool_2001 = edx > edi[0x15c03b];
            if (bool_2002) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_2001) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;

loc_44b640:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_1989 = edx < edi[0x15c03b];
            bool_1987 = edx > edi[0x15c03b];
            if (bool_1989) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_1987) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;

.l42:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_1995 = edx > edi[0x15c03b];
            if (edx < edi[0x15c03b]) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_1995) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;

.l45:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_2011 = edx < edi[0x15c03b];
            bool_2010 = edx > edi[0x15c03b];
            if (bool_2011) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_2010) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;

.l59:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_2022 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_2022) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto .l61;

.l60:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    eax = *(int16_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
    bool_2032 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_2032) {
            eax = 0x14;
    }
    if (eax != decomp_var_b4) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_2021 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_2021) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto .l64;

.l50:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_2023 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_2023) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto .l62;

.l53:
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    eax = esi[0x3];
    eax = *(int16_t *)(decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x20);
    bool_2018 = HIBYTE(eax) == 0x41;
    eax = eax & 0xff;
    if (!bool_2018) {
            eax = 0x14;
    }
    if (eax != decomp_var_b4) {
            sub_401520();
            esi = decomp_var_74;
            edi = decomp_var_78;
            ebx = decomp_var_9c;
            continue;
    }
    if (esi == edi[0x1]) {
            sub_47a948();
    }
    bool_2024 = esi != edi[0x1];
    eax = esi[0x3];
    ebx = decomp_var_b8[0x2] + (eax + eax * 0x8) * 0x4 + 0x8;
    if (!bool_2024) {
            sub_47a948();
    }
    edx = esi[0x3];
    edi = *ebx[0x1];
    esi = ebx;
    decomp_var_a4 = edx;
    decomp_var_4c = esi;
    decomp_var_48 = edi;
    goto .l63;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;

.l61:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_2044 = edx > edi[0x15c03b];
            if (edx < edi[0x15c03b]) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_2044) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;

.l64:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_2069 = edx < edi[0x15c03b];
            bool_2066 = edx > edi[0x15c03b];
            if (bool_2069) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_2066) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;

.l62:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_2056 = edx < edi[0x15c03b];
            bool_2052 = edx > edi[0x15c03b];
            if (bool_2056) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_2052) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;

.l63:
    eax = decomp_var_30;
    ebx = eax[0x1];
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esi = decomp_var_48 + decomp_var_a4 + 0x4000;
            esp = esp - 0x4;
            decomp_var_b8 = &decomp_var_90;
            eax = sub_41c1e0(decomp_var_b8);
            edx = eax[0x1];
            edi = decomp_var_24;
            bool_2060 = edx < edi[0x15c03b];
            bool_2059 = edx > edi[0x15c03b];
            if (bool_2060) {
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (bool_2059) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            if (*eax > edi[0x15c03a]) {
                    esp = esp - 0x4;
                    decomp_var_b8 = &decomp_var_90;
                    eax = sub_41c1e0(decomp_var_b8);
                    edi[0x15c03a] = *eax;
                    edi[0x15c03b] = eax[0x1];
                    sub_401590();
                    edi = decomp_var_34;
                    esi = decomp_var_38;
                    continue;
            }
            sub_401590();
            edi = decomp_var_34;
            esi = decomp_var_38;
            continue;
    }
    break;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;
    sub_401520();
    esi = decomp_var_74;
    edi = decomp_var_78;
    ebx = decomp_var_9c;
    continue;
}
