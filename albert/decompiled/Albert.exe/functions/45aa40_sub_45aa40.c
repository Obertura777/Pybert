// sub_45aa40 @ 0x45aa40
// hopper name: sub_45aa40
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45aa40() {
    var_C = *0x0;
    decomp_var_30 = esi;
    decomp_var_34 = *dword_4c8db8 ^ &decomp_var_30;
    *0x0 = &var_C;
    esi = ecx;
    sub_465870();
    eax = sub_464460(&var_1C);
    esp = esp - 0x3c;
    sub_465ff0(eax);
    sub_465fa0();
    if (sub_4658d0() > 0x1) {
            eax = sub_464460(&var_1C);
            esp = esp - 0x8;
            sub_45a9b0(eax);
            sub_465fa0();
    }
    eax = sub_465fa0();
    *0x0 = var_C;
    return eax;
}
