// ComputeDrawVote @ 0x4440e0
// hopper name: sub_4440e0
// pybert name: ComputeDrawVote
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_0afa075b2357e4b9dab27931e9af2938342b65cf9c4c106cd2c94cf72d880b91
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

ComputeDrawVote() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_118 = ebx;
    decomp_var_11c = esi;
    decomp_var_120 = edi;
    esp = esp - 0x124;
    decomp_var_124 = *dword_4c8db8 ^ &decomp_var_120;
    *0x0 = &var_C;
    var_10C = ecx;
    esi = 0x0;
    var_F0 = 0x0;
    eax = sub_410330();
    var_D8 = eax;
    eax[0x19] = 0x1;
    var_D8[0x1] = var_D8;
    *var_D8 = var_D8;
    var_D8[0x2] = var_D8;
    eax = sub_4602b0();
    var_FC = eax;
    eax[0x29] = 0x1;
    var_FC[0x1] = var_FC;
    *var_FC = var_FC;
    var_FC[0x2] = var_FC;
    var_F8 = 0x0;
    eax = sub_401e30();
    eax[0x11] = 0x1;
    eax[0x1] = eax;
    *eax = eax;
    eax[0x2] = eax;
    eax = sub_401e30();
    eax[0x11] = 0x1;
    eax[0x1] = eax;
    *eax = eax;
    eax[0x2] = eax;
    eax = ecx[0x2];
    var_7C = 0x0;
    var_74 = 0x0;
    var_68 = 0x0;
    var_C4 = 0x0;
    if (eax[0x900] <= 0x0) goto loc_4442f5;
    goto loc_44421a;

loc_4442f5:
    esi = var_10C[0x2];
    eax = esi[0x915];
    esi = esi + 0x2450;
    edi = *eax;
    var_108 = esi;
    var_104 = edi;
    goto loc_444320;

loc_44421a:
    goto loc_444220;

loc_444320:
    eax = var_10C[0x2];
    ebx = eax[0x915];
    eax = eax + 0x2450;
    if (esi == 0x0 || esi != eax) {
            sub_47a948();
    }
    if (edi != ebx) {
            var_A0 = arg_0[0x1];
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_90, edi + 0x18, decomp_var_124, decomp_var_120, decomp_var_11c);
            ebx = eax;
            eax = *ebx;
            if (eax == 0x0 || eax != arg_0) {
                    sub_47a948();
            }
            if (ebx[0x1] == var_A0) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x4;
                    *(int8_t *)(sub_422200(edi + 0x10) + 0x14) = 0x1;
                    sub_401390();
                    edi = var_104;
                    esi = var_108;
                    continue;
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            ebx = edi + 0x10;
            esp = esp - 0x4;
            *(int8_t *)sub_422170(ebx) = 0x1;
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = *ebx;
            if (*(int8_t *)(var_10C[0x2] + (eax + eax * 0x8) * 0x4 + 0x4) == 0x1) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    var_F4 = *ebx;
                    esp = esp - 0x4;
                    var_F0 = *(int16_t *)word_4c6c08;
                    eax = sub_422170(&var_F4);
                    *(int8_t *)eax = 0x1;
                    sub_401390();
                    edi = var_104;
                    esi = var_108;
                    continue;
            }
            sub_401390();
            edi = var_104;
            esi = var_108;
            continue;
    }
    break;

loc_444220:
    ebx = eax + (esi + esi * 0x8) * 0x4 + 0x8;
    esp = esp - 0x4;
    var_F4 = esi;
    eax = sub_422200(&var_C4);
    *eax = var_7C;
    eax[0x1] = var_7C | 0xffffffff;
    eax[0x2] = var_74;
    eax[0x3] = 0x0;
    eax[0x4] = 0x0;
    eax[0x5] = var_68;
    edi = ebx;
    var_C0 = edi;
    var_BC = *ebx[0x1];
    goto loc_444273;
    eax = sub_444460(decomp_var_124, decomp_var_120, decomp_var_11c, decomp_var_118, decomp_var_114, decomp_var_110, var_10C, var_108, var_104, var_100, var_FC, var_F8, var_F4, var_F0, decomp_var_ec, &var_DC, *var_D8, decomp_var_e0, var_DC, var_D8);
    return eax;

loc_444273:
    var_A0 = ebx[0x1];
    if (edi == 0x0 || edi != ebx) {
            sub_47a948();
    }
    if (var_BC != var_A0) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (var_BC == edi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x4;
            var_F0 = var_BC[0x6];
            eax = sub_422170(&var_F4);
            *(int8_t *)eax = 0x0;
            sub_401590();
            edi = var_C0;
            continue;
    }
    break;
    eax = var_10C[0x2];
    esi = esi + 0x1;
    var_C4 = esi;
    if (esi < eax[0x900]) {
            continue;
    }
    break;
}
