// sub_45a090 @ 0x45a090
// hopper name: sub_45a090
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45a090() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_78 = ebx;
    decomp_var_7c = esi;
    decomp_var_80 = edi;
    decomp_var_84 = *dword_4c8db8 ^ &decomp_var_80;
    *0x0 = &var_C;
    var_6C = ecx;
    eax = sub_466060(&var_20, 0x1);
    eax = sub_466060(&var_30, 0x3);
    esp = esp - 0x9c;
    var_70 = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    eax = sub_465900(&var_74, 0x0);
    if (*(int16_t *)word_4c6d48 == *(int16_t *)eax) goto loc_45a2b3;
    goto loc_45a12a;

loc_45a2b3:
    sub_465fa0();
    sub_465fa0();
    *0x0 = var_C;
    &var_74 = ebp;
    return;

loc_45a12a:
    eax = sub_466060(&var_40, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    esp = esp - 0x14;
    eax = sub_465900(&var_74, 0x0);
    if (*(int16_t *)word_4c6dcc == *(int16_t *)eax) goto loc_45a2b3;
    goto loc_45a180;

loc_45a180:
    esi = **dword_bb65cc;
    edi = 0xbb65c8;
    var_68 = 0xbb65c8;
    var_64 = **dword_bb65cc;
    goto loc_45a194;

loc_45a194:
    if (edi == 0x0 || edi != 0xbb65c8) {
            sub_47a948();
    }
    if (esi != *dword_bb65cc) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            eax = sub_465d90(&var_30);
            if (eax == 0x0) {
                    sub_40f860();
                    esi = var_64;
                    edi = var_68;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_20 = esi != edi[0x1];
            ebx = esi + 0x30;
            var_5C = esi[0xd];
            if (!bool_20) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_50, &var_70, decomp_var_84, decomp_var_80, decomp_var_7c);
            ecx = *eax;
            var_74 = eax;
            if (ecx == 0x0 || ecx != ebx) {
                    sub_47a948();
                    eax = var_74;
            }
            if (eax[0x1] == var_5C) {
                    sub_40f860();
                    esi = var_64;
                    edi = var_68;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_17 = esi != edi[0x1];
            ebx = esi + 0x3c;
            var_54 = esi[0x10];
            if (!bool_17) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_48, &var_70, decomp_var_84, decomp_var_80, decomp_var_7c);
            ecx = *eax;
            var_74 = eax;
            if (ecx == 0x0 || ecx != ebx) {
                    sub_47a948();
                    eax = var_74;
            }
            if (eax[0x1] == var_54) {
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
                    eax = sub_404ce0(&var_40, &var_70, decomp_var_84);
            }
            sub_40f860();
            esi = var_64;
            edi = var_68;
            continue;
    }
    break;
    sub_457520();
    goto loc_45a2b3;
}
