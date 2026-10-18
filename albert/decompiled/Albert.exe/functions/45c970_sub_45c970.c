// sub_45c970 @ 0x45c970
// hopper name: sub_45c970
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_45c970() {
    var_C = *0x0;
    decomp_var_50 = ebx;
    decomp_var_54 = ebp;
    decomp_var_58 = esi;
    decomp_var_5c = edi;
    esp = esp - 0x60;
    decomp_var_60 = *dword_4c8db8 ^ &decomp_var_5c;
    *0x0 = &var_C;
    ebp = ecx;
    sub_465870();
    esi = 0x0;
    sub_465870();
    edi = arg_0;
    if (*edi == 0x0) {
            sub_47a948();
    }
    if (edi[0x1] == *(*edi + 0x4)) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_465ff0(edi[0x1] + 0x18);
    if (sub_4658d0() > 0x0) {
            ebx = arg_4;
            do {
                    esp = esp - 0x8;
                    eax = sub_465900(&arg_0, esi);
                    if (*(int16_t *)ebx != *(int16_t *)eax) {
                            eax = sub_465900(&arg_4, esi);
                            eax = sub_466480(&var_2C, eax);
                            esp = esp - 0x14;
                            sub_465ff0(eax);
                            sub_465fa0();
                    }
                    esi = esi + 0x1;
            } while (esi < sub_4658d0());
    }
    if (*edi == 0x0) {
            sub_47a948();
    }
    if (edi[0x1] == *(*edi + 0x4)) {
            sub_47a948();
    }
    sub_465ff0(&var_3C);
    esp = esp - 0xc;
    eax = sub_466f80(&var_1C, &var_3C);
    esi = eax;
    if (*edi == 0x0) {
            sub_47a948();
    }
    if (edi[0x1] == *(*edi + 0x4)) {
            sub_47a948();
    }
    eax = edi[0x1];
    eax = sub_466c40(&var_2C, eax + 0x28);
    sub_45a9b0(eax);
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = var_C;
    return eax;
}
