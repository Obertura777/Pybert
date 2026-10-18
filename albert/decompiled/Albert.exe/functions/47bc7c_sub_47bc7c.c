// sub_47bc7c @ 0x47bc7c
// hopper name: sub_47bc7c
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47bc7c() {
    esp = esp - 0x8;
    sub_47f31c(0x4c33a0, 0xc);
    decomp_var_1c = decomp_var_1c | 0xffffffff;
    esi = arg_4;
    if (esi == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
    }
    else {
            if ((esi[0xc] & 0x40) != 0x0) {
                    esi[0x3] = 0x0;
            }
            else {
                    sub_4868de(esi);
                    decomp_var_1c = sub_47bc09(esi);
                    sub_47bcf0();
            }
    }
    eax = sub_47f361();
    return eax;
}
