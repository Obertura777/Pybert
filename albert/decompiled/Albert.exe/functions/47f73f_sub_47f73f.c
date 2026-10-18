// sub_47f73f @ 0x47f73f
// hopper name: sub_47f73f
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_90494415b61eb82ac839c6366207db207de74b6d5171126d2db053d56f8875a3
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_47f73f() {
    esp = esp - 0x8;
    sub_47f31c(0x4c3550, 0x10);
    ebx = arg_4;
    if (ebx == 0x0) {
            *sub_47d812() = 0x16;
            sub_47a924();
            eax = sub_47f361();
    }
    else {
            if (*dword_bc720c == 0x3) {
                    sub_487c06(0x4);
                    eax = sub_487d79(ebx);
                    esp = ((esp - 0x4) + 0x4 - 0x4) + 0x4;
                    decomp_var_20 = eax;
                    if (eax != 0x0) {
                            esi = *(ebx - 0x4);
                            esi = esi - 0x9;
                    }
                    else {
                            esi = decomp_var_1c;
                    }
                    sub_47f7d9();
                    if (decomp_var_20 == 0x0) {
                            esi = HeapSize(*dword_bc69f4, 0x0, ebx);
                            eax = sub_47f361();
                    }
                    else {
                            eax = sub_47f361();
                    }
            }
            else {
                    esi = HeapSize(*dword_bc69f4, 0x0, ebx);
                    eax = sub_47f361();
            }
    }
    return eax;
}
