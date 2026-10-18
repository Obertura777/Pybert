// sub_45b1e0 @ 0x45b1e0
// hopper name: sub_45b1e0
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b1e0() {
    var_C = *0x0;
    decomp_var_9c = ebx;
    decomp_var_a0 = esi;
    decomp_var_a4 = edi;
    decomp_var_a8 = *dword_4c8db8 ^ &decomp_var_a4;
    *0x0 = &var_C;
    esi = ecx;
    var_90 = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_466060(&var_8C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_4658f0(&var_92);
    var_98 = *(int16_t *)eax & 0xffff;
    eax = sub_466060(&var_8C, 0x3);
    sub_465ff0(eax);
    sub_465fa0();
    esp = esp - 0xcc;
    eax = sub_465900(&var_92, 0x0);
    if ((*(int16_t *)word_4c7088 & 0xffff) != *(int16_t *)eax) {
            esp = esp - 0x8;
            eax = sub_465900(&var_90, 0x0);
            if (*(int16_t *)word_4c7180 != *(int16_t *)eax) {
                    eax = sub_4665f0(&var_1C, &var_7C);
                    eax = sub_466f80(&var_3C, eax);
                    edi = eax;
                    sub_466ed0(&var_4C, &var_98);
                    eax = sub_466c40(&var_8C, edi);
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_466f80(&var_4C, &var_6C);
                    edi = eax;
                    sub_466ed0(&var_3C, &var_98);
                    eax = sub_466c40(&var_1C, edi);
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_45a9b0(&var_2C);
                    esp = esp - 0x48;
                    eax = sub_45a9b0(&var_6C);
            }
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = var_C;
    return eax;
}
