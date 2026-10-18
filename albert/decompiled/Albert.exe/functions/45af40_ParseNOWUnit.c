// ParseNOWUnit @ 0x45af40
// hopper name: sub_45af40
// pybert name: ParseNOWUnit
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ParseNOWUnit() {
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
            eax = sub_466060(&var_2C, 0x1);
            (*(*esi + 0x90))(arg_0, eax);
            eax = sub_465fa0();
            *0x0 = var_C;
    }
    else {
            esp = esp - 0x8;
            eax = sub_465900(&arg_4, 0x0);
            if (*(int16_t *)word_4c7074 != *(int16_t *)eax) {
                    eax = sub_466060(&var_1C, 0x1);
                    (*(*esi + 0x94))(arg_0, eax);
                    eax = sub_465fa0();
                    *0x0 = var_C;
            }
            else {
                    eax = (*(*esi + 0xc8))(arg_0);
                    *0x0 = var_C;
            }
    }
    return eax;
}
