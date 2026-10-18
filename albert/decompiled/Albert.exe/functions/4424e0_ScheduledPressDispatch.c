// ScheduledPressDispatch @ 0x4424e0
// hopper name: sub_4424e0
// pybert name: ScheduledPressDispatch
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ScheduledPressDispatch() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_7c = ebx;
    decomp_var_80 = ebp;
    decomp_var_84 = esi;
    decomp_var_88 = edi;
    decomp_var_8c = *dword_4c8db8 ^ &decomp_var_88;
    *0x0 = &var_C;
    ebp = ecx;
    var_6C = ebp;
    sub_465870();
    sub_465870();
    eax = sub_47b26f(0x0);
    esp = (esp - 0x90) + 0x4;
    eax = eax - *dword_ba2880;
    var_60 = eax;
    var_5C = edx - *dword_ba2884 + CARRY(EFLAGS(cf));
    goto loc_442559;

loc_442559:
    esi = **dword_bb65c0;
    ebx = 0xbb65bc;
    var_64 = **dword_bb65c0;
    var_68 = 0xbb65bc;
    goto loc_442570;

loc_442570:
    if (ebx == 0x0 || ebx != 0xbb65bc) {
            sub_47a948();
    }
    if (esi == *dword_bb65c0) goto loc_44272b;
    goto loc_44258f;

loc_44272b:
    sub_465fa0();
    sub_465fa0();
    *0x0 = var_C;
    &decomp_var_78 = decomp_var_80;
    return;

loc_44258f:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    ecx = esi[0x5];
    bool_12 = ecx < var_5C;
    if (ecx > var_5C) {
            sub_40e210();
            esi = var_64;
            ebx = var_68;
            continue;
    }
    if (!bool_12 && esi[0x4] > var_60) {
            sub_40e210();
            esi = var_64;
            ebx = var_68;
            continue;
    }
    break;
    if (esi == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x8;
    eax = sub_465900(&var_74, 0x0);
    if (*(int16_t *)word_4c6d34 != *(int16_t *)eax) {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            sub_45a9b0(esi + 0x18);
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            eax = sub_466060(&var_30, 0x2);
            esp = esp - 0xc;
            sub_465ff0(eax);
            sub_465fa0();
            ebp = sub_465930();
            edi = 0x0;
            if (ebp > 0x0) {
                    do {
                            eax = sub_465900(&var_72, edi);
                            esp = esp - 0xc;
                            sub_421570(*(int8_t *)eax & 0xff);
                            edi = edi + 0x1;
                    } while (edi < ebp);
            }
    }
    else {
            if (esi == ebx[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_465900(&var_70, 0x0);
            if (*(int16_t *)word_4c6de4 != *(int16_t *)eax) {
                    if (esi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = sub_466060(&var_20, 0x1);
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = sub_465900(&var_6E, 0x0);
                    esp = esp - 0x18;
                    sub_439c30(*(int8_t *)eax & 0xff);
            }
    }
    esp = esp - 0xc;
    eax = sub_411fb0(&var_58, ebx, esi, decomp_var_8c, decomp_var_88, decomp_var_84, decomp_var_80, decomp_var_7c, decomp_var_78, var_74, var_70, var_6C, var_68, var_64, var_60, var_5C, var_58, decomp_var_54);
    ebp = var_6C;
    continue;
}
