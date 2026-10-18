// sub_460110 @ 0x460110
// hopper name: sub_460110
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_460110() {
    var_C = *0x0;
    decomp_var_74 = ebx;
    decomp_var_78 = ebp;
    decomp_var_7c = esi;
    decomp_var_80 = edi;
    esp = esp - 0x84;
    decomp_var_84 = *dword_4c8db8 ^ &decomp_var_80;
    *0x0 = &var_C;
    ebp = ecx;
    edi = arg_0;
    sub_465870();
    esi = arg_4;
    eax = esi[0x4];
    eax = eax - 0x0;
    if (eax != 0x0) {
            eax = eax - 0x7;
            if (eax != 0x0) {
                    if (eax == 0x1) {
                            sub_45ffa0(&var_1C, esi);
                            eax = sub_466480(&var_2C, word_4c7690);
                            esp = esp - 0x14;
                            sub_465ff0(eax);
                            sub_465fa0();
                            sub_465fa0();
                            eax = edi;
                            *0x0 = var_C;
                    }
                    else {
                            eax = edi;
                            *0x0 = var_C;
                    }
            }
            else {
                    decomp_var_8c = esi[0x5];
                    eax = sub_45fca0(&var_3C, decomp_var_8c, esi[0xc]);
                    ebx = eax;
                    sub_45ffa0(&var_4C, esi);
                    sub_466480(&var_5C, word_4c7694);
                    eax = sub_466330(&var_6C, ebx);
                    esp = esp - 0x28;
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = edi;
                    *0x0 = var_C;
            }
    }
    else {
            sub_45ffa0(&var_1C, esi);
            eax = sub_466480(&var_2C, word_4c7690);
            esp = esp - 0x14;
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            eax = edi;
            *0x0 = var_C;
    }
    return eax;
}
