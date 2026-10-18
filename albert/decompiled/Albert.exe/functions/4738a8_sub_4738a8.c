// sub_4738a8 @ 0x4738a8
// hopper name: sub_4738a8
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_7eaefcae85d881030ab52580d0138645a5f7610a1853d5e3198d2c7a6fa244cc
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4738a8() {
    decomp_var_4 = 0x14;
    sub_47f31c(0x4c29c8, 0x14);
    esi = ecx;
    decomp_var_1c = decomp_var_1c & 0x0;
    sub_4715ba(&decomp_var_1c);
    esp = esp - 0x10;
    if (sub_470ded() != 0x0) {
            sub_47387e();
            esi = esi[0x4];
            eax = 0x0;
            if (esi == 0x0) {
                    sub_46dedc();
            }
            (esi)();
            sub_47390b();
            eax = sub_47f361();
    }
    else {
            eax = sub_47f361();
    }
    return eax;
}
