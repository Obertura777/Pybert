// sub_45b630 @ 0x45b630
// hopper name: sub_45b630
// referenced by: pointer
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45b630() {
    var_C = *0x0;
    decomp_var_40 = esi;
    decomp_var_44 = *dword_4c8db8 ^ &decomp_var_40;
    *0x0 = &var_C;
    esi = ecx;
    eax = *esi;
    eax = eax[0x16];
    esp = esp - 0x4c;
    var_38 = 0x0;
    var_30 = 0x0;
    var_34 = 0x0;
    eax = (eax)(&var_38, &var_30, decomp_var_44, decomp_var_40, ebx, var_38, 0x0, var_30);
    if (eax != 0x0) {
            var_28 = var_24 & 0x3fff;
            sub_466ed0(&var_10, &var_2C);
            eax = sub_466e10(&var_20, &var_28);
            sub_45a9b0(eax);
            sub_465fa0();
            eax = sub_465fa0();
            *0x0 = saved_fp;
    }
    else {
            if (esi[0x28] != 0x0) {
                    esi[0x28] = 0x0;
            }
            *0x0 = saved_fp;
    }
    return eax;
}
