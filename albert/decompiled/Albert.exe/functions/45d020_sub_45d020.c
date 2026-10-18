// sub_45d020 @ 0x45d020
// hopper name: sub_45d020
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45d020() {
    decomp_var_c = *0x0;
    decomp_var_14 = ebp;
    decomp_var_18 = esi;
    decomp_var_1c = edi;
    esp = esp - 0x20;
    decomp_var_20 = *dword_4c8db8 ^ &decomp_var_1c;
    *0x0 = &decomp_var_c;
    ebp = arg_4;
    ecx = *(*ebp - 0x10);
    if (ecx != 0x0) {
            eax = *(*ecx + 0x10);
            eax = (eax)();
            if (eax == 0x0) {
                    eax = sub_47020b();
                    eax = *(*eax + 0x10);
                    eax = (eax)();
            }
    }
    else {
            eax = sub_47020b();
            eax = *(*eax + 0x10);
            eax = (eax)();
    }
    if (eax == 0x0) {
            eax = sub_40b5a0(0x80004005);
    }
    else {
            esi = arg_0;
            *esi = (*(*eax + 0xc))() + 0x10;
            edi = arg_8;
            if (edi == 0x0) {
                    eax = 0x0;
            }
            else {
                    eax = edi;
                    edx = eax + 0x1;
                    do {
                            ecx = *(int8_t *)eax;
                            eax = eax + 0x1;
                    } while (ecx != 0x0);
                    eax = eax - edx;
            }
            sub_40c390();
            eax = esi;
            *0x0 = decomp_var_c;
    }
    return eax;
}
