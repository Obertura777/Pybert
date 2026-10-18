// sub_4460a0 @ 0x4460a0
// hopper name: sub_4460a0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_4460a0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    decomp_var_94 = ebx;
    decomp_var_98 = ebp;
    decomp_var_9c = esi;
    var_A0 = edi;
    esp = esp - 0xa4;
    var_7C = ecx;
    sub_410c70(*(*dword_baed74 + 0x4));
    eax = *dword_baed74;
    eax[0x1] = eax;
    eax = *dword_baed74;
    *dword_baed78 = 0x0;
    *eax = eax;
    eax = *dword_baed74;
    eax[0x2] = eax;
    eax = arg_0;
    var_8C = 0x0;
    if (eax[0x901] <= 0x0) goto loc_44652a;
    goto loc_4460fb;

loc_44652a:
    &var_90 = decomp_var_98;
    return eax;

loc_4460fb:
    var_90 = 0x0;
    var_80 = &arg_3FF8;
    &var_A0 = &var_A0;
    goto loc_446110;

loc_446110:
    ebx = eax + 0x2450;
    edi = *eax[0x915];
    var_88 = ebx;
    var_84 = edi;
    &var_A0 = &var_A0;
    goto loc_446130;

loc_446130:
    esi = arg_0[0x915];
    eax = arg_0 + 0x2450;
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi == esi) goto .l20;
    goto loc_446153;

.l20:
    break;

loc_446153:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    if (edi[0x6] != var_8C) {
            sub_401390();
            ebx = var_88;
            edi = var_84;
            continue;
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_4075b0(edi + 0x14, var_A0);
    edi = *eax[0x1];
    ebx = eax;
    var_60 = eax;
    var_78 = ebx;
    var_74 = edi;
    goto loc_4461b0;
    eax = arg_0;
    var_80 = var_80 + 0xc;
    var_90 = var_90 + 0x100;
    bool_1 = var_8C + 0x1 < eax[0x901];
    var_8C = var_8C + 0x1;
    if (bool_1) {
            continue;
    }
    break;

loc_4461b0:
    esi = eax[0x1];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi == esi) goto .l17;
    goto loc_4461c8;

.l17:
    break;

loc_4461c8:
    if (ebx == 0x0) {
            sub_47a948();
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    eax = edi[0x3];
    esi = edi + 0xc;
    if (*(eax * 0x8 + 0x5b98e8) != 0x1) {
            sub_40f400();
            ebx = var_78;
            edi = var_74;
            eax = var_60;
            continue;
    }
    if (*(eax * 0x8 + 0x5b98ec) != 0x0) {
            sub_40f400();
            ebx = var_78;
            edi = var_74;
            eax = var_60;
            continue;
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    eax = *esi;
    eax = eax + var_90;
    if (*(eax * 0x8 + 0x520ce8) != 0x1 || *(eax * 0x8 + 0x520cec) != 0x0) {
            sub_40f400();
            ebx = var_78;
            edi = var_74;
            eax = var_60;
            continue;
    }
    if (edi == ebx[0x1]) {
            sub_47a948();
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
    }
    esp = esp - 0x4;
    eax = sub_41c1e0(esi);
    ecx = *esi;
    ecx = ecx + var_90;
    if (*eax != *(ecx * 0x8 + 0x55b0e8)) {
            sub_40f400();
            ebx = var_78;
            edi = var_74;
            eax = var_60;
            continue;
    }
    if (eax[0x1] != *(ecx * 0x8 + 0x55b0ec)) {
            sub_40f400();
            ebx = var_78;
            edi = var_74;
            eax = var_60;
            continue;
    }
    if (var_84 == var_88[0x1]) {
            sub_47a948();
    }
    var_24 = arg_8;
    if (edi == ebx[0x1]) {
            sub_47a948();
    }
    esp = esp - 0x4;
    eax = sub_407720(esi);
    bool_18 = edi != ebx[0x1];
    esi = eax;
    var_1C = *esi;
    if (!bool_18) {
            sub_47a948();
    }
    var_18 = edi[0x8];
    esp = esp - 0x4;
    ebp = sub_4075b0(esi + 0x4, var_A0);
    ebx = *ret_addr;
    edi = ebp;
    var_54 = ebp;
    var_70 = edi;
    var_6C = ebx;
    goto loc_4462f0;
    sub_401390();
    ebx = var_88;
    edi = var_84;
    continue;

loc_4462f0:
    esi = ret_addr;
    if (edi == 0x0 || edi != ebp) {
            sub_47a948();
    }
    if (ebx == esi) goto .l14;
    goto loc_446308;

.l14:
    break;

loc_446308:
    if (edi == 0x0) {
            sub_47a948();
    }
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    eax = ebx[0x3];
    eax = eax + var_90;
    esi = ebx + 0xc;
    if (*(eax * 0x8 + 0x520ce8) != 0x1) {
            sub_40f400();
            ebx = var_6C;
            edi = var_70;
            continue;
    }
    if (*(eax * 0x8 + 0x520cec) != 0x0) {
            sub_40f400();
            ebx = var_6C;
            edi = var_70;
            continue;
    }
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    if (var_84 == var_88[0x1]) {
            sub_47a948();
    }
    if (*esi == var_84[0x4]) {
            sub_40f400();
            ebx = var_6C;
            edi = var_70;
            continue;
    }
    if (ebx == edi[0x1]) {
            sub_47a948();
    }
    ebx = sub_407720(esi);
    esp = esp - 0x8;
    var_58 = ebx;
    ebp = sub_4075b0(ebx + 0x4, var_A0);
    edi = *ret_addr;
    esi = ebp;
    var_5C = ebp;
    var_68 = esi;
    var_64 = edi;
    &var_A0 = &var_A0;
    goto loc_4463c0;
    sub_40f400();
    ebx = var_78;
    edi = var_74;
    eax = var_60;
    continue;

loc_4463c0:
    var_2C = ret_addr;
    if (esi == 0x0 || esi != ebp) {
            sub_47a948();
    }
    if (edi != var_2C) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x3] == var_24) {
                    ebp = *ebx;
                    ebx = var_6C;
                    if (ebx == var_70[0x1]) {
                            sub_47a948();
                    }
                    bool_44 = edi != esi[0x1];
                    ebx = ebx[0x8];
                    if (!bool_44) {
                            sub_47a948();
                    }
                    esi = edi[0x8];
                    edi = var_74;
                    if (edi == var_78[0x1]) {
                            sub_47a948();
                    }
                    var_50 = *((edi[0x3] + var_90) * 0x8 + 0x55b0e8);
                    esp = esp - 0x8;
                    eax = sub_419800(&var_C, &var_50, var_A0);
                    ebp = var_5C;
                    ebx = var_58;
            }
            sub_40f400();
            edi = var_64;
            esi = var_68;
            continue;
    }
    break;
    ebp = var_54;
    sub_40f400();
    ebx = var_6C;
    edi = var_70;
    continue;
}
