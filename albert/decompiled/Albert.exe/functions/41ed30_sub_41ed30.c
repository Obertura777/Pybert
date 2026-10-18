// sub_41ed30 @ 0x41ed30
// hopper name: sub_41ed30
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_c03725b85e1a9d1ef0c6f267cdb1d15d9ff41d82303047abfd8153cd763b76ce
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_41ed30() {
    var_C = *0x0;
    decomp_var_78 = edi;
    decomp_var_7c = *dword_4c8db8 ^ &decomp_var_78;
    *0x0 = &var_C;
    *(int16_t *)arg_0 = 0x0;
    sub_465870();
    sub_465870();
    eax = sub_401e30();
    var_44 = eax;
    eax[0x11] = 0x1;
    var_44[0x1] = var_44;
    *var_44 = var_44;
    var_44[0x2] = var_44;
    eax = sub_401e30();
    var_50 = eax;
    eax[0x11] = 0x1;
    var_50[0x1] = var_50;
    *var_50 = var_50;
    var_50[0x2] = var_50;
    ebp = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    var_67 = 0x0;
    var_68 = 0x0;
    eax = sub_466480(&var_3C, &arg_14);
    sub_465ff0(eax);
    var_4 = 0x5;
    sub_465fa0();
    esp = esp - 0x8c;
    esi = sub_465930();
    sub_401950(var_50[0x1]);
    var_50[0x1] = var_50;
    var_4C = 0x0;
    *var_50 = var_50;
    edi = 0x0;
    var_50[0x2] = var_50;
    if (esi > 0x0) {
            do {
                    eax = sub_465900(&var_66, edi);
                    var_64 = *(int8_t *)eax & 0xff;
                    esp = esp - 0x10;
                    eax = sub_404ce0(&var_60, &var_64, decomp_var_7c);
                    edi = edi + 0x1;
            } while (edi < esi);
    }
    if (sub_465930() == 0x2) {
            eax = sub_466060(&var_3C, 0x1);
            esp = esp - 0xc;
            sub_465ff0(eax);
            var_4 = 0x5;
            sub_465fa0();
            var_60 = sub_465930();
            eax = var_44;
            edi = eax[0x1];
            esi = edi;
            if (edi[0x11] == 0x0) {
                    do {
                            sub_401950(esi[0x2]);
                            esi = *esi;
                            sub_47c8f9();
                            esp = (esp - 0x8) + 0x4;
                            edi = esi;
                    } while (esi[0x11] == 0x0);
                    eax = var_44;
            }
            eax[0x1] = eax;
            *var_44 = var_44;
            esi = 0x0;
            var_44[0x2] = var_44;
            if (var_60 > 0x0) {
                    do {
                            eax = sub_465900(&var_66, esi);
                            edi = *(int8_t *)eax & 0xff;
                            esp = esp - 0x10;
                            var_64 = edi;
                            eax = sub_404ce0(&var_3C, &var_64, decomp_var_7c);
                            if (edi == ebp) {
                                    var_67 = 0x1;
                            }
                            esi = esi + 0x1;
                    } while (esi < var_60);
                    if (var_67 == 0x1) {
                            var_68 = 0x1;
                    }
            }
    }
    else {
            var_68 = 0x1;
    }
    if (*(int8_t *)byte_baed5d != 0x0 && var_68 == 0x1) {
            *(int16_t *)arg_0 = *(int16_t *)word_4c6d48;
    }
    else {
            *(int16_t *)arg_0 = *(int16_t *)word_4c6d28;
    }
    sub_403430(&var_38, &var_2C, *var_28, &var_2C, var_28);
    sub_47c8f9();
    sub_403430(&var_38, &var_20, *var_1C, &var_20, var_1C);
    sub_47c8f9();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = arg_28;
    *0x0 = arg_18;
    return eax;
}
