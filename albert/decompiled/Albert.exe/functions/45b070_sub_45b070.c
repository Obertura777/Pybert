// sub_45b070 @ 0x45b070
// hopper name: sub_45b070
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b070() {
    var_C = *0x0;
    decomp_var_30 = esi;
    decomp_var_34 = edi;
    decomp_var_38 = *dword_4c8db8 ^ &decomp_var_34;
    *0x0 = &var_C;
    esi = ecx;
    edi = arg_4;
    esp = esp - 0x40;
    eax = sub_465900(&arg_4, 0x0);
    if (*(int16_t *)word_4c707c != *(int16_t *)eax) {
            esp = esp - 0x8;
            eax = sub_466060(&var_2C, 0x1);
            edx = *esi;
            edx = edx[0x2d];
            var_4 = 0x0;
            (edx)(arg_8, eax);
            eax = sub_465fa0();
            *0x0 = var_4;
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&arg_4, 0x0);
            if (*(int16_t *)word_4c7074 != *(int16_t *)eax) {
                    esp = esp - 0x8;
                    eax = sub_466060(&var_2C, 0x1);
                    edx = *esi;
                    edx = edx[0x2e];
                    var_4 = 0x1;
                    (edx)(arg_8, eax);
                    eax = sub_465fa0();
                    *0x0 = var_4;
            }
            else {
                    esp = esp - 0x8;
                    eax = sub_465900(&arg_4, 0x0);
                    if (*(int16_t *)word_4c70d0 != *(int16_t *)eax) {
                            eax = sub_466060(&var_1C, 0x1);
                            (*(*esi + 0xbc))(arg_0, eax);
                            eax = sub_465fa0();
                            *0x0 = var_C;
                    }
                    else {
                            eax = (*(*esi + 0xd0))(arg_0);
                            *0x0 = var_C;
                    }
            }
    }
    return eax;
}
