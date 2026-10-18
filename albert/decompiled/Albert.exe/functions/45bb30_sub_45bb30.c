// sub_45bb30 @ 0x45bb30
// hopper name: sub_45bb30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45bb30() {
    decomp_var_4 = ebx;
    ebx = arg_c;
    decomp_var_8 = esi;
    esi = arg_10;
    esp = esp - 0xc;
    decomp_var_c = edi;
    edi = arg_8;
    goto loc_45bb40;

loc_45bb40:
    eax = arg_0;
    if (eax == 0x0 || eax != edi) {
            eax = sub_47a948();
    }
    if (arg_4 != ebx) {
            *esi = *esi + 0x1;
            sub_40f580();
            continue;
    }
    break;
    return eax;
}
