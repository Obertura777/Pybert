// sub_40d4d0 @ 0x40d4d0
// hopper name: sub_40d4d0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_66b5090999fc6ba8fbd4a50175157b8ab59088d79c29def336840695ba7d7fdb
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_40d4d0() {
    var_C = *0x0;
    decomp_var_9c = ebx;
    decomp_var_a0 = esi;
    decomp_var_a4 = edi;
    decomp_var_a8 = *dword_4c8db8 ^ &decomp_var_a4;
    *0x0 = &var_C;
    esi = ecx;
    var_90 = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    eax = sub_466060(&var_7C, 0x1);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_4658f0(&var_92);
    var_98 = *(int16_t *)eax & 0xffff;
    eax = sub_466060(&var_7C, 0x3);
    sub_465ff0(eax);
    sub_465fa0();
    esp = esp - 0xcc;
    eax = sub_465900(&var_92, 0x0);
    if ((*(int16_t *)word_4c6cf0 & 0xffff) != *(int16_t *)eax) {
            esp = esp - 0x8;
            eax = sub_465900(&var_90, 0x0);
            if (*(int16_t *)word_4c6de8 != *(int16_t *)eax) {
                    eax = sub_4665f0(&var_1C, &var_8C);
                    eax = sub_466f80(&var_3C, eax);
                    edi = eax;
                    sub_466ed0(&var_5C, &var_98);
                    eax = sub_466c40(&var_7C, edi);
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_466f80(&var_5C, 0xbb6f0c);
                    edi = eax;
                    sub_466ed0(&var_3C, &var_98);
                    eax = sub_466c40(&var_1C, edi);
                    sub_465ff0(eax);
                    sub_465fa0();
                    sub_465fa0();
                    sub_465fa0();
                    eax = sub_45a9b0(&var_4C);
                    esp = esp - 0x48;
                    eax = sub_45a9b0(&var_2C);
            }
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = sub_465fa0();
    *0x0 = var_C;
    return eax;
}
