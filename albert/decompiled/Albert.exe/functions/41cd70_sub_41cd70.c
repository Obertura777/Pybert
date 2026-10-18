// sub_41cd70 @ 0x41cd70
// hopper name: sub_41cd70
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41cd70() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_38 = ebx;
    decomp_var_3c = esi;
    esp = esp - 0x40;
    decomp_var_40 = edi;
    edi = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    esi = **(ecx + ((edi << 0x4) - edi) * 0x8 + 0x3620);
    ebx = ecx + ((edi << 0x4) - edi) * 0x8 + 0x361c;
    eax = ebx;
    var_2C = ecx;
    var_18 = 0x1;
    var_14 = 0x0;
    var_30 = ebx;
    var_28 = eax;
    var_24 = esi;
    goto loc_41cdc0;

loc_41cdc0:
    var_4 = ebx[0x1];
    if (eax == 0x0 || eax != ebx) {
            sub_47a948();
            eax = var_28;
    }
    if (esi != var_4) {
            if (eax == 0x0) {
                    sub_47a948();
                    eax = var_28;
            }
            if (esi == eax[0x1]) {
                    sub_47a948();
            }
            edx = esi[0x4];
            eax = esi[0x5];
            esi = 0x0;
            var_20 = edx;
            var_1C = eax;
            var_10 = 0x0;
            ebx = 0x0;
            var_34 = var_30;
            do {
                    eax = sub_41c1e0(&var_20);
                    esp = esp - 0x14;
                    var_10 = var_10 + sub_47bb70(*(arg_0 + esi * 0x8), *(arg_0 + esi * 0x8 + 0x4), *eax, eax[0x1]);
                    ebx = ebx + edx + CARRY(EFLAGS(cf));
                    var_34 = var_34 + 0xc;
                    esi = esi + 0x1;
            } while (esi < 0xa);
            esp = esp - 0x10;
            esi = var_10 + sub_47bb70(*(((edi << 0x8) + var_20) * 0x8 + 0x6040e8), *(((edi << 0x8) + var_20) * 0x8 + 0x6040ec), arg_4, arg_8);
            ebx = ebx + edx + CARRY(EFLAGS(cf));
            bool_1 = ebx > var_14;
            if (ebx >= var_14 && (bool_1 || esi > var_18)) {
                    var_18 = esi;
                    var_14 = ebx;
            }
            esp = esp - 0x4;
            eax = sub_41c1e0(&var_20);
            *eax = esi;
            eax[0x1] = ebx;
            sub_40f6f0();
            esi = var_24;
            ebx = var_30;
            eax = var_28;
            continue;
    }
    break;
    esi = *ebx[0x1];
    eax = ebx;
    var_28 = eax;
    var_24 = esi;
    goto loc_41cee0;

loc_41cee0:
    var_4 = ebx[0x1];
    if (eax == 0x0 || eax != ebx) {
            sub_47a948();
            eax = var_28;
    }
    if (esi != var_4) {
            if (eax == 0x0) {
                    sub_47a948();
                    eax = var_28;
            }
            if (esi == eax[0x1]) {
                    sub_47a948();
            }
            edx = esi[0x5];
            ebx = esi[0x4];
            var_1C = edx;
            esi = var_2C + (edi + edi * 0x2) * 0x4 + 0x4000;
            var_20 = ebx;
            eax = sub_41c1e0(&var_20);
            var_C = edx;
            var_10 = sub_47bac0(sub_47bb70(*eax, eax[0x1], 0x3e8, 0x0), edx, var_18, var_14);
            eax = sub_41c1e0(&var_20);
            *eax = var_10;
            eax[0x1] = var_C;
            esp = esp - 0x2c;
            eax = sub_41c1e0(&var_20);
            edx = eax[0x1];
            bool_17 = edx > *(((edi << 0x8) + ebx) * 0x8 + 0x55b0ec);
            bool_14 = edx < *(((edi << 0x8) + ebx) * 0x8 + 0x55b0ec);
            ebx = ((edi << 0x8) + ebx) * 0x8 + 0x55b0e8;
            if (bool_14) {
                    sub_40f6f0();
                    esi = var_24;
                    ebx = var_30;
                    eax = var_28;
                    continue;
            }
            if (bool_17) {
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&var_20);
                    *ebx = *eax;
                    ebx[0x1] = eax[0x1];
                    sub_40f6f0();
                    esi = var_24;
                    ebx = var_30;
                    eax = var_28;
                    continue;
            }
            if (*eax > *ebx) {
                    esp = esp - 0x4;
                    eax = sub_41c1e0(&var_20);
                    *ebx = *eax;
                    ebx[0x1] = eax[0x1];
                    sub_40f6f0();
                    esi = var_24;
                    ebx = var_30;
                    eax = var_28;
                    continue;
            }
            sub_40f6f0();
            esi = var_24;
            ebx = var_30;
            eax = var_28;
            continue;
    }
    break;
    esi = ebx;
    var_28 = esi;
    var_24 = *ebx[0x1];
    goto loc_41cff3;

loc_41cff3:
    var_4 = ebx[0x1];
    if (esi == 0x0 || esi != ebx) {
            sub_47a948();
    }
    if (var_24 != var_4) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (var_24 == esi[0x1]) {
                    sub_47a948();
            }
            esi = var_24[0x4];
            eax = var_24[0x5];
            var_20 = esi;
            var_1C = eax;
            if (*(int16_t *)word_4c6c08 != eax) {
                    sub_40f6f0();
                    esi = var_28;
                    continue;
            }
            esp = esp - 0x4;
            var_30 = var_2C + (edi + edi * 0x2) * 0x4 + 0x4000;
            eax = sub_41c1e0(&var_20);
            edx = eax[0x1];
            bool_29 = edx > *(((edi << 0x8) + esi) * 0x8 + 0x55b0ec);
            bool_21 = edx < *(((edi << 0x8) + esi) * 0x8 + 0x55b0ec);
            esi = ((edi << 0x8) + esi) * 0x8 + 0x55b0e8;
            if (bool_29) {
                    sub_40f6f0();
                    esi = var_28;
                    continue;
            }
            if (bool_21) {
                    eax = sub_41c1e0(&var_20);
                    esp = esp - 0x8;
                    var_34 = eax;
                    eax = sub_41c1e0(&var_20);
                    ecx = *esi;
                    ecx = ecx - *eax;
                    edx = esi[0x1];
                    esi = var_34;
                    var_10 = ecx;
                    var_C = edx - eax[0x1] + CARRY(EFLAGS(cf));
                    asm { fild       qword [esp+0x40+var_10] };
                    asm { fmul       qword [qword_value_4599075939470750515] };
                    asm { fild       qword [esi] };
                    asm { faddp      st1 };
                    *esi = sub_47b5f6();
                    esi[0x1] = edx;
                    sub_40f6f0();
                    esi = var_28;
                    continue;
            }
            if (*eax < *esi) {
                    eax = sub_41c1e0(&var_20);
                    esp = esp - 0x8;
                    var_34 = eax;
                    eax = sub_41c1e0(&var_20);
                    ecx = *esi;
                    ecx = ecx - *eax;
                    edx = esi[0x1];
                    esi = var_34;
                    var_10 = ecx;
                    var_C = edx - eax[0x1] + CARRY(EFLAGS(cf));
                    asm { fild       qword [esp+0x40+var_10] };
                    asm { fmul       qword [qword_value_4599075939470750515] };
                    asm { fild       qword [esi] };
                    asm { faddp      st1 };
                    *esi = sub_47b5f6();
                    esi[0x1] = edx;
                    sub_40f6f0();
                    esi = var_28;
                    continue;
            }
            sub_40f6f0();
            esi = var_28;
            continue;
    }
    break;
    esi = edi + edi * 0x2 + edi + edi * 0x2 + edi + edi * 0x2 + edi + edi * 0x2 + 0xbc2028;
    var_30 = edi + edi * 0x2 + edi + edi * 0x2 + edi + edi * 0x2 + edi + edi * 0x2;
    edi = *(*(edi + edi * 0x2 + edi + edi * 0x2 + edi + edi * 0x2 + edi + edi * 0x2 + 0xbc202c) + 0x4);
    var_2C = edi;
    if (edi[0x21] == 0x0) {
            do {
                    sub_40faf0(edi[0x2]);
                    edi = *edi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    var_2C = edi;
            } while (edi[0x21] == 0x0);
    }
    eax = esi[0x1];
    eax[0x1] = eax;
    eax = esi[0x1];
    esi[0x2] = 0x0;
    *eax = eax;
    eax = esi[0x1];
    eax[0x2] = eax;
    eax = sub_41d160(decomp_var_40, decomp_var_3c, decomp_var_38, var_34, var_30, var_2C, ebx, *ebx[0x1], var_20, var_1C, var_18, var_14, var_10, var_C, decomp_var_8);
    return eax;
}
