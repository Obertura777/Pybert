// sub_481ce6 @ 0x481ce6
// hopper name: sub_481ce6
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_481ce6() {
    decomp_var_4 = 0xc;
    esp = esp - 0x8;
    sub_47f31c(0x4c3798, 0xc);
    esi = sub_480086();
    if (!CPU_FLAGS & E) {
            if (esi[0x1b] != 0x0) {
                    esi = *(sub_480086() + 0x6c);
                    if (esi == 0x0) {
                            sub_47d856(0x20);
                    }
                    eax = sub_47f361();
            }
            else {
                    sub_487c06(0xc);
                    esp = (esp - 0x4) + 0x4;
                    sub_481ca8();
                    sub_481d50();
                    if (esi == 0x0) {
                            sub_47d856(0x20);
                    }
                    eax = sub_47f361();
            }
    }
    else {
            sub_487c06(0xc);
            esp = (esp - 0x4) + 0x4;
            sub_481ca8();
            sub_481d50();
            if (esi == 0x0) {
                    sub_47d856(0x20);
            }
            eax = sub_47f361();
    }
    return eax;
}
