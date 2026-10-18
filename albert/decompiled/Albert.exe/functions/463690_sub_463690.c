// sub_463690 @ 0x463690
// hopper name: sub_463690
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_463690() {
    var_C = *0x0;
    decomp_var_1fc = ebx;
    decomp_var_200 = ebp;
    decomp_var_204 = esi;
    decomp_var_208 = edi;
    esp = esp - 0x20c;
    decomp_var_20c = *dword_4c8db8 ^ &decomp_var_208;
    *0x0 = &var_C;
    edi = ecx;
    ebp = arg_0;
    sub_465870();
    sub_465870();
    esi = arg_4;
    eax = esi[0x4];
    if (eax > 0x6) goto loc_463d02;
    goto loc_46370d;

loc_463d02:
    sub_465fa0();
    eax = ebp;
    *0x0 = var_C;
    return eax;

loc_46370d:
    if (*(eax * 0x4 + switch_table) == 0x0) goto loc_463714;
    goto .l6;

loc_463714:
    sub_45ffa0(&var_EC, esi);
    eax = sub_466480(&var_10C, word_4c7680);
    esp = esp - 0x14;
    sub_465ff0(eax);
    sub_465fa0();
    goto loc_463cf5;

.l6:
    if (*(eax * 0x4 + switch_table) == 0x1) goto loc_463770;
    goto .l7;

loc_463cf5:
    sub_465fa0();
    goto loc_463d02;

loc_463770:
    decomp_var_214 = esi[0x5];
    eax = sub_45fca0(&var_CC, decomp_var_214, esi[0xc]);
    ebx = eax;
    sub_45ffa0(&var_18C, esi);
    sub_466480(&var_4C, word_4c7684);
    eax = sub_466330(&var_1AC, ebx);
    esp = esp - 0x28;
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    goto loc_463cf5;

.l7:
    if (*(eax * 0x4 + switch_table) == 0x2) goto loc_463835;
    goto .l8;

loc_463835:
    eax = sub_407720(esi + 0x1c);
    eax = sub_45ffa0(&var_AC, eax);
    ebx = eax;
    sub_45ffa0(&var_14C, esi);
    sub_466480(&var_6C, word_4c7688);
    eax = sub_466330(&var_16C, ebx);
    esp = esp - 0x28;
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    goto loc_463cf5;

.l8:
    if (*(eax * 0x4 + switch_table) == 0x3) goto loc_4638fa;
    goto .l9;

loc_4638fa:
    eax = sub_407720(esi + 0x1c);
    eax = sub_45ffa0(&var_1BC, eax);
    ebx = eax;
    sub_45ffa0(&var_1CC, esi);
    sub_466480(&var_8C, word_4c7688);
    sub_466330(&var_1DC, ebx);
    sub_466480(&var_2C, word_4c7684);
    esi = esi[0x8];
    eax = sub_466480(&var_12C, edi + (esi + esi * 0x8) * 0x4);
    esp = esp - 0x38;
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    goto loc_463cf5;

.l9:
    if (*(eax * 0x4 + switch_table) == 0x4) goto loc_463a12;
    goto loc_463b36;

loc_463a12:
    eax = sub_407720(esi + 0x1c);
    eax = sub_45ffa0(&var_FC, eax);
    ebx = eax;
    sub_45ffa0(&var_11C, esi);
    sub_466480(&var_13C, word_4c767c);
    sub_466330(&var_15C, ebx);
    sub_466480(&var_17C, word_4c7678);
    esi = esi[0x8];
    eax = sub_466480(&var_19C, edi + (esi + esi * 0x8) * 0x4);
    esp = esp - 0x38;
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    goto loc_463cf5;

loc_463b36:
    decomp_var_214 = esi[0x5];
    eax = sub_45fca0(&var_7C, decomp_var_214, esi[0xc]);
    ebx = eax;
    sub_45ffa0(&var_9C, esi);
    sub_466480(&var_BC, word_4c7678);
    eax = sub_466330(&var_DC, ebx);
    esp = esp - 0x28;
    sub_465ff0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    ebx = esi + 0x24;
    esi = *esi[0xa];
    goto loc_463c13;

loc_463c13:
    eax = ebx;
    var_1F4 = ebx[0x1];
    if (eax == 0x0 || eax != ebx) {
            sub_47a948();
    }
    if (esi != var_1F4) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = esi[0x2];
            eax = sub_466480(&var_5C, edi + (eax + eax * 0x8) * 0x4);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            esi = *esi;
            continue;
    }
    break;
    sub_466480(&var_1C, 0x4c768c);
    eax = sub_466c40(&var_3C, &var_1EC);
    esp = esp - 0x14;
    sub_465ff0(eax);
    sub_465fa0();
    goto loc_463cf5;
}
