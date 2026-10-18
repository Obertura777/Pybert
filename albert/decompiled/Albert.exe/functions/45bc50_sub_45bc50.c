// sub_45bc50 @ 0x45bc50
// hopper name: sub_45bc50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_8cdae819e06820f977b0a9eb334f03bb92b3255f52bbe6a5afcd50c02b80b706
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45bc50() {
    var_C = *0x0;
    decomp_var_14 = ebx;
    decomp_var_18 = ebp;
    decomp_var_1c = esi;
    decomp_var_20 = edi;
    esp = esp - 0x24;
    decomp_var_24 = *dword_4c8db8 ^ &decomp_var_20;
    *0x0 = &var_C;
    ebx = ecx;
    eax = ebx[0x1];
    esi = *eax;
    *eax = eax;
    eax = ebx[0x1];
    eax[0x1] = eax;
    bool_0 = esi == ebx[0x1];
    ebx[0x2] = 0x0;
    if (!bool_0) {
            do {
                    ebp = *esi;
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x4) + 0x4;
                    esi = ebp;
            } while (ebp != ebx[0x1]);
    }
    *0x0 = var_C;
    return;
}
