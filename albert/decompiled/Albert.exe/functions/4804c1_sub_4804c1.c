// sub_4804c1 @ 0x4804c1
// hopper name: sub_4804c1
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4804c1() {
    decomp_var_4 = 0x10;
    esp = esp - 0x8;
    sub_47f31c(0x4c35d8, 0x10);
    edi = arg_c;
    ebx = arg_4;
    if (edi[0x1] <= 0x80) {
            esi = sign_extend_32(ebx[0x8]);
    }
    else {
            esi = ebx[0x2];
    }
    eax = sub_480086();
    eax[0x24] = eax[0x24] + 0x1;
    goto loc_4804f8;

loc_4804f8:
    if (esi != arg_10) {
            if (esi <= 0xffffffff || esi >= edi[0x1]) {
                    sub_4810dd();
            }
            eax = esi << 0x3;
            ecx = edi[0x2];
            esi = *(ecx + eax);
            decomp_var_4 = 0x1;
            if (*(ecx + eax + 0x4) != 0x0) {
                    ebx[0x2] = esi;
                    esp = esp - 0xc;
                    sub_481130(*(edi[0x2] + eax + 0x4), ebx, 0x103);
            }
            continue;
    }
    break;
    sub_480587();
    if (esi != arg_10) {
            sub_4810dd();
    }
    ebx[0x2] = esi;
    eax = sub_47f361();
    return eax;
}
