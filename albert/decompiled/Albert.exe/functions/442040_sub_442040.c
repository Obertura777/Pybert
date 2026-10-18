// sub_442040 @ 0x442040
// hopper name: sub_442040
// contains unmarked entry 0x442230
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_442040() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_a8 = edi;
    esp = esp - 0xac;
    *0x0 = &var_C;
    ebx = ecx;
    eax = sub_4103b0();
    var_98 = eax;
    eax[0x21] = 0x1;
    var_98[0x1] = var_98;
    *var_98 = var_98;
    var_98[0x2] = var_98;
    var_94 = 0x0;
    eax = ebx[0x2];
    edi = eax[0x2424] & 0xff;
    esi = eax + 0x24b4;
    var_90 = esi;
    var_8C = *eax[0x92e];
    goto loc_4420d0;

loc_4420d0:
    eax = ebx[0x2];
    ecx = eax[0x92e];
    eax = eax + 0x24b4;
    var_64 = ecx;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (var_88 != var_64) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (var_88 == esi[0x1]) {
                    sub_47a948();
            }
            esi = sub_407720(var_88 + 0xc);
            var_24 = *sub_41c1e0(esi) + 0xc8;
            var_18 = esi[0x2];
            esp = esp - 0x10;
            eax = sub_41a010(&var_84, &var_24, decomp_var_a8);
            sub_401520();
            esi = var_8C;
            continue;
    }
    break;
    eax = arg_0;
    if (eax <= 0x0) goto loc_442486;
    goto loc_4421a0;

loc_442486:
    sub_4150e0(&var_18, &var_8C, *var_88, &var_8C, var_88);
    eax = sub_47c8f9();
    *0x0 = ret_addr;
    &var_8C = ebp;
    return eax;

loc_4421a0:
    edi = &var_98;
    var_8C = eax;
    goto loc_4421b0;

loc_4421b0:
    esi = var_90;
    *dword_baed34 = *dword_baed34 + 0x1;
    var_54 = edi;
    var_50 = esi;
    sub_40f660();
    if (var_54 == 0x0) {
            sub_47a948();
    }
    if (var_50 == var_54[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_46db50();
    eax = sub_4273a0(decomp_var_a8);
    if (eax[0x6] >= 0x10) {
            var_2C = eax[0x1];
    }
    else {
            var_2C = eax + 0x4;
    }
    var_70 = edi;
    var_6C = esi;
    sub_40f660();
    if (var_70 == 0x0) {
            sub_47a948();
    }
    if (var_6C == var_70[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    sub_46db50();
    eax = sub_4273a0(decomp_var_a4);
    if (eax[0x6] >= 0x10) {
            eax = eax[0x1];
    }
    else {
            eax = eax + 0x4;
    }
    sub_45abe0();
    var_78 = 0x0;
    var_74 = edi;
    esp = (esp - 0x10) + 0x10;
    var_70 = esi;
    sub_40f660();
    eax = var_74;
    var_4 = *var_88;
    if (eax == 0x0 || eax != &var_8C) {
            sub_47a948();
    }
    if (var_70 != var_4) {
            var_54 = edi;
            var_50 = esi;
            sub_40f660();
            if (var_54 == 0x0) {
                    sub_47a948();
            }
            eax = var_50;
            if (eax == var_54[0x1]) {
                    sub_47a948();
                    eax = var_50;
            }
            if ((eax[0x4] | eax[0x5]) != 0x0) {
                    var_3C = edi;
                    var_38 = esi;
                    sub_40f660();
                    if (var_3C == 0x0) {
                            sub_47a948();
                    }
                    if (var_38 == var_3C[0x1]) {
                            sub_47a948();
                    }
                    var_44 = edi;
                    var_40 = esi;
                    sub_40f660();
                    if (var_44 == 0x0) {
                            sub_47a948();
                    }
                    if (var_40 == var_44[0x1]) {
                            sub_47a948();
                    }
                    var_20 = var_74;
                    var_1C = var_70;
                    sub_40f660();
                    if (var_20 == 0x0) {
                            sub_47a948();
                    }
                    if (var_1C == var_20[0x1]) {
                            sub_47a948();
                    }
                    var_34 = var_74;
                    var_30 = var_70;
                    sub_40f660();
                    if (var_34 == 0x0) {
                            sub_47a948();
                    }
                    if (var_30 == var_34[0x1]) {
                            sub_47a948();
                    }
                    var_2C = edi;
                    var_28 = esi;
                    sub_40f660();
                    if (var_2C == 0x0) {
                            sub_47a948();
                    }
                    if (var_28 == var_2C[0x1]) {
                            sub_47a948();
                    }
            }
    }
    var_64 = edi;
    var_60 = esi;
    sub_40f660();
    if (var_64 == 0x0) {
            sub_47a948();
    }
    if (var_60 == var_64[0x1]) {
            sub_47a948();
    }
    sub_461010(var_60[0x6]);
    var_5C = edi;
    sub_40f660();
    esp = esp - 0x10;
    eax = sub_412800(&var_18, var_5C, var_58, var_9C, var_98, var_94, var_90, var_8C, var_88, var_84, var_80, decomp_var_7c, var_78, var_74, var_70, var_6C, decomp_var_68, var_64);
    var_80 = var_80 - 0x1;
    if (var_80 != 0x0) {
            continue;
    }
    break;
}
