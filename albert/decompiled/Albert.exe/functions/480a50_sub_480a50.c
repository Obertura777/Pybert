// sub_480a50 @ 0x480a50
// hopper name: sub_480a50
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_480a50() {
    decomp_var_4 = 0x8;
    esp = esp - 0x8;
    sub_47f31c(0x4c36c0, 0x8);
    eax = arg_c;
    if ((*eax & 0x80000000) != 0x0) {
            ebx = arg_8;
    }
    else {
            ebx = eax[0x2] + arg_8 + 0xc;
    }
    esi = arg_10;
    decomp_var_c = esi;
    decomp_var_10 = eax;
    decomp_var_14 = arg_8;
    edi = arg_4;
    eax = sub_4808d1();
    esp = (esp - 0x10) + 0x10;
    eax = eax - 0x1;
    if (eax != 0x0) {
            if (eax == 0x1) {
                    sub_48063b(edi[0x6], esi + 0x8);
                    sub_47a9d2(ebx, esi[0x6]);
            }
    }
    else {
            sub_48063b(edi[0x6], esi + 0x8);
            sub_47a9d2(ebx, esi[0x6]);
    }
    eax = sub_47f361();
    return eax;
}
