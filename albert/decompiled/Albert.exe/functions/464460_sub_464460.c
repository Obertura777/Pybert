// sub_464460 @ 0x464460
// hopper name: sub_464460
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_06c2a82957024defebbb838e2588454e9b17c066babec8d06687ed96047429d4
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_464460() {
    var_C = *0x0;
    decomp_var_c4 = ebx;
    decomp_var_c8 = ebp;
    decomp_var_cc = esi;
    decomp_var_d0 = edi;
    var_D4 = *dword_4c8db8 ^ &decomp_var_d0;
    *0x0 = &var_C;
    esi = ecx;
    ebp = arg_0;
    sub_465870();
    sub_465870();
    sub_465f30(0x4c77a0);
    esp = esp - 0xdc;
    eax = sub_465ff0(&var_A0);
    sub_465fa0();
    eax = esi[0x1225] & 0xffff;
    if (*(int16_t *)word_4c772c == eax) goto loc_46491b;
    goto loc_464511;

loc_46491b:
    ebx = esi + 0x2450;
    edi = *esi[0x915];
    var_BC = edi;
    goto .l7;

loc_464511:
    if (*(int16_t *)word_4c7734 == eax) goto .l6;
    goto loc_46451e;

.l7:
    eax = esi + 0x2450;
    var_98 = esi[0x915];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != var_98) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] != (esi[0x2424] & 0xff)) {
                    sub_401390();
                    edi = var_B8;
                    ebx = var_BC;
                    continue;
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x8] != 0x0) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = sub_463690(&var_8C, edi + 0x10);
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = sub_466c40(&var_7C, &var_B4);
                    esp = esp - 0x18;
                    var_D4 = eax;
                    sub_465ff0(var_D4);
                    sub_465fa0();
            }
            sub_401390();
            edi = var_B8;
            ebx = var_BC;
            continue;
    }
    break;

.l6:
    ebx = esi + 0x2450;
    edi = *esi[0x915];
    var_BC = edi;
    goto loc_464940;

loc_46451e:
    if (*(int16_t *)word_4c7730 == eax) goto .l2;
    goto loc_46452b;
    sub_465fa0();
    eax = ebp;
    *0x0 = var_C;
    return eax;

loc_464940:
    eax = esi + 0x2450;
    var_98 = esi[0x915];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != var_98) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] == (esi[0x2424] & 0xff)) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x8] != 0x0) {
                            if (edi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            eax = sub_463690(&var_8C, edi + 0x10);
                            sub_465ff0(eax);
                            sub_465fa0();
                            eax = sub_466c40(&var_7C, &var_B4);
                            esp = esp - 0x18;
                            var_D4 = eax;
                            sub_465ff0(var_D4);
                            sub_465fa0();
                    }
            }
            sub_401390();
            edi = var_B8;
            ebx = var_BC;
            continue;
    }
    break;

.l2:
    ebx = esi + 0x245c;
    edi = *esi[0x918];
    var_C0 = ebx;
    var_BC = edi;
    &var_D4 = &var_D4;
    goto loc_464840;

loc_46452b:
    if (*(int16_t *)word_4c7738 == eax) goto loc_464821;
    goto loc_464538;
    sub_465fa0();
    eax = ebp;
    *0x0 = var_C;
    return eax;

loc_464840:
    eax = esi + 0x245c;
    var_9C = esi[0x918];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != var_9C) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] != (esi[0x2424] & 0xff)) {
                    sub_401390();
                    edi = var_BC;
                    ebx = var_C0;
                    continue;
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x8] != 0x0) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    eax = sub_460110(&var_90, edi + 0x10);
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = sub_466c40(&var_80, &var_B8);
                    esp = esp - 0x18;
                    sub_465ff0(eax);
                    sub_465fa0();
            }
            sub_401390();
            edi = var_BC;
            ebx = var_C0;
            continue;
    }
    break;

loc_464821:
    ebx = esi + 0x245c;
    edi = *esi[0x918];
    var_C0 = ebx;
    var_BC = edi;
    &var_D4 = &var_D4;
    goto .l8;

loc_464538:
    ebx = esi + 0x2474;
    edi = *esi[0x91e];
    goto loc_464550;
    sub_465fa0();
    eax = ebp;
    *0x0 = var_C;
    return eax;

.l8:
    eax = esi + 0x245c;
    var_9C = esi[0x918];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != var_9C) {
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (edi[0x6] == (esi[0x2424] & 0xff)) {
                    if (edi == ebx[0x1]) {
                            sub_47a948();
                    }
                    if (edi[0x8] != 0x0) {
                            if (edi == ebx[0x1]) {
                                    sub_47a948();
                            }
                            eax = sub_460110(&var_90, edi + 0x10);
                            sub_465ff0(eax);
                            sub_465fa0();
                            eax = sub_466c40(&var_80, &var_B8);
                            esp = esp - 0x18;
                            sub_465ff0(eax);
                            sub_465fa0();
                    }
            }
            sub_401390();
            edi = var_BC;
            ebx = var_C0;
            continue;
    }
    break;

loc_464550:
    eax = esi + 0x2474;
    var_9C = esi[0x91e];
    if (ebx == 0x0 || ebx != eax) {
            sub_47a948();
    }
    if (edi != var_9C) {
            sub_465f30(esi + 0x2424);
            esp = esp - 0x8;
            eax = sub_465ff0(&var_6C);
            sub_465fa0();
            if (ebx == 0x0) {
                    sub_47a948();
            }
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            if (*(int16_t *)word_4c7670 == edi[0x8]) {
                    eax = sub_466480(&var_5C, word_4c7670);
                    esp = esp - 0xc;
                    decomp_var_d8 = eax;
                    sub_465ff0(decomp_var_d8);
            }
            else {
                    eax = sub_466480(&var_3C, word_4c7674);
                    esp = esp - 0xc;
                    decomp_var_d8 = eax;
                    sub_465ff0(decomp_var_d8);
            }
            sub_465fa0();
            if (edi == ebx[0x1]) {
                    sub_47a948();
            }
            decomp_var_d8 = edi[0x3];
            eax = sub_45fca0(&var_28, decomp_var_d8, edi[0x8]);
            eax = sub_466330(&var_18, eax);
            esp = esp - 0x18;
            sub_465ff0(eax);
            sub_465fa0();
            sub_465fa0();
            sub_465aa0();
            if (esi[0x2488] != 0x0) {
                    eax = sub_466480(&var_48, word_4c7698);
                    esp = esp - 0xc;
                    sub_465ff0(eax);
            }
            else {
                    eax = sub_466480(&var_7C, 0x4c769c);
                    esp = esp - 0xc;
                    sub_465ff0(eax);
            }
            sub_465fa0();
            var_D4 = &var_88;
            eax = sub_466c40(var_D4, &var_B0);
            esp = esp - 0xc;
            decomp_var_d0 = eax;
            sub_465ff0(decomp_var_d0);
            sub_465fa0();
            sub_40e680();
            edi = var_9C;
            ebx = var_A0;
            continue;
    }
    break;
    sub_465fa0();
    eax = ebp;
    *0x0 = var_C;
    return eax;
    edi = 0x0;
    if (esi[0x920] > 0x0) {
            ebx = esi + 0x2424;
            do {
                    eax = sub_466540(&var_90, word_4c76a0);
                    sub_465ff0(eax);
                    sub_465fa0();
                    eax = sub_466c40(&var_80, &var_B8);
                    esp = esp - 0x18;
                    sub_465ff0(eax);
                    sub_465fa0();
                    edi = edi + 0x1;
            } while (edi < esi[0x920]);
    }
    sub_465fa0();
    eax = ebp;
    *0x0 = var_C;
    return eax;
}
