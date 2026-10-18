// sub_41ea20 @ 0x41ea20
// hopper name: sub_41ea20
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41ea20() {
    var_C = *0x0;
    decomp_var_78 = edi;
    var_7C = *dword_4c8db8 ^ &decomp_var_78;
    *0x0 = &var_C;
    ebp = arg_0;
    *(int16_t *)ebp = 0x0;
    sub_465870();
    sub_465870();
    eax = sub_401e30();
    var_50 = eax;
    eax[0x11] = 0x1;
    var_50[0x1] = var_50;
    *var_50 = var_50;
    var_50[0x2] = var_50;
    eax = sub_401e30();
    var_44 = eax;
    eax[0x11] = 0x1;
    var_44[0x1] = var_44;
    *var_44 = var_44;
    var_44[0x2] = var_44;
    var_5C = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    arg_0 = 0x0;
    eax = sub_466480(&var_3C, &arg_14);
    sub_465ff0(eax);
    sub_465fa0();
    eax = sub_466060(&var_3C, 0x1);
    sub_465ff0(eax);
    var_4 = 0x5;
    sub_465fa0();
    esi = sub_465930();
    var_60 = sub_465930();
    sub_401950(var_50[0x1]);
    var_50[0x1] = var_50;
    var_4C = 0x0;
    *var_50 = var_50;
    var_50[0x2] = var_50;
    esp = esp - 0x9c;
    sub_401950(var_44[0x1]);
    var_44[0x1] = var_44;
    *var_44 = var_44;
    edi = 0x0;
    var_44[0x2] = var_44;
    if (esi > 0x0) {
            do {
                    eax = sub_465900(&var_66, edi);
                    var_64 = *(int8_t *)eax & 0xff;
                    esp = esp - 0x10;
                    eax = sub_404ce0(&var_3C, &var_64, var_7C);
                    edi = edi + 0x1;
            } while (edi < esi);
    }
    esi = 0x0;
    if (var_60 > 0x0) {
            &var_7C = &var_7C;
            do {
                    eax = sub_465900(&var_66, esi);
                    edi = *(int8_t *)eax & 0xff;
                    esp = esp - 0x10;
                    var_64 = edi;
                    eax = sub_404ce0(&var_3C, &var_64, var_7C);
                    if (edi == var_5C) {
                            arg_0 = 0x1;
                    }
                    esi = esi + 0x1;
            } while (esi < var_60);
    }
    if (var_4C == 0x1 && arg_0 == 0x1) {
            *(int16_t *)ebp = *(int16_t *)word_4c6d48;
    }
    else {
            *(int16_t *)ebp = *(int16_t *)word_4c6d28;
    }
    sub_403430(&var_34, &var_20, *var_1C, &var_20, var_1C);
    sub_47c8f9();
    sub_403430(&var_34, &var_2C, *var_28, &var_2C, var_28);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = ebp;
    *0x0 = arg_18;
    return eax;
}
