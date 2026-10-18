// sub_405ed0 @ 0x405ed0
// hopper name: sub_405ed0
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_5cc63cb94071c63420dabfd8b5335985b2493814f2238a7b3efca7a872bd75f9
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_405ed0() {
    &saved_fp = &saved_fp & 0xfffffff8;
    var_C = *0x0;
    decomp_var_b8 = ebx;
    decomp_var_bc = esi;
    decomp_var_c0 = edi;
    var_C4 = *dword_4c8db8 ^ &decomp_var_c0;
    *0x0 = &var_C;
    esi = ecx;
    var_70 = esi;
    eax = sub_40ff50();
    var_94 = eax;
    eax[0x15] = 0x1;
    var_94[0x1] = var_94;
    *var_94 = var_94;
    var_94[0x2] = var_94;
    var_90 = 0x0;
    eax = sub_40ff50();
    var_AC = eax;
    eax[0x15] = 0x1;
    var_AC[0x1] = var_AC;
    *var_AC = var_AC;
    var_AC[0x2] = var_AC;
    var_A8 = 0x0;
    eax = sub_40ff50();
    var_A0 = eax;
    eax[0x15] = 0x1;
    var_A0[0x1] = var_A0;
    *var_A0 = var_A0;
    var_A0[0x2] = var_A0;
    var_9C = 0x0;
    ebx = arg_0;
    eax = *ebx;
    ecx = *(esi + (eax + eax * 0x8) * 0x4 + 0x18);
    esi = esi + (eax + eax * 0x8) * 0x4 + 0x14;
    var_68 = ecx;
    esp = esp - 0xcc;
    var_7C = 0x0;
    var_B1 = 0x0;
    eax = sub_401ff0(&var_50, ebx + 0x8, var_C4, decomp_var_c0, decomp_var_bc);
    edi = eax;
    eax = *edi;
    if (eax == 0x0 || eax != esi) {
            sub_47a948();
    }
    if (edi[0x1] != var_68) goto loc_40633d;
    goto loc_405feb;

loc_40633d:
    sub_405190(&var_5C, &var_A4, *var_A0, &var_A4, var_A0);
    sub_47c8f9();
    sub_405190(&var_5C, &var_B0, *var_AC, &var_B0, var_AC);
    sub_47c8f9();
    sub_405190(&var_5C, &var_98, *var_94, &var_98, var_94);
    sub_47c8f9();
    eax = var_7C;
    *0x0 = var_C;
    &decomp_var_b4 = ebp;
    return eax;

loc_405feb:
    var_84 = *ebx;
    esp = esp - 0x8;
    var_80 = 0x0;
    eax = sub_404fd0(&var_5C, &var_84, var_C4);
    &var_C4 = &var_C4;
    goto loc_406010;

loc_406010:
    edi = *var_AC;
    var_7C = var_7C + 0x1;
    esi = &var_B0;
    var_8C = esi;
    var_88 = edi;
    goto loc_406027;

loc_406027:
    ebx = var_AC;
    if (esi == 0x0 || esi != &var_B0) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            eax = edi[0x3];
            ebx = **(var_70 + (eax + eax * 0x8) * 0x4 + 0xc);
            eax = var_70 + (eax + eax * 0x8) * 0x4 + 0x8;
            esi = eax;
            var_84 = esi;
            var_80 = ebx;
            &var_C4 = &var_C4;
            edi = eax[0x1];
            if (esi == 0x0 || esi != eax) {
                    sub_47a948();
            }
            if (ebx == edi) {
                    sub_40f400();
                    edi = var_88;
                    esi = var_8C;
                    continue;
            }
            if (esi == 0x0) {
                    sub_47a948();
                    temp_0 = 0x0;
            }
            else {
                    temp_0 = 0x0;
            }
            break;
    }
    else {
            temp_0 = 0x1;
            break;
    }
    goto .l3;

.l3:
    if (temp_0 == 0x0) goto loc_4060a1;
    goto loc_406253;

loc_4060a1:
    if (ebx == esi[0x1]) {
            sub_47a948();
            temp_1 = 0x0;
    }
    else {
            temp_1 = 0x0;
    }
    break;

loc_406253:
    edi = *var_AC;
    esi = &var_B0;
    var_8C = esi;
    var_88 = edi;
    goto loc_406265;
    if (temp_1 != 0x0) {
            sub_405190(&var_5C, &var_A4, *var_A0, &var_A4, var_A0);
            sub_47c8f9();
            sub_405190(&var_5C, &var_B0, *var_AC, &var_B0, var_AC);
            sub_47c8f9();
            sub_405190(&var_5C, &var_98, *var_94, &var_98, var_94);
            sub_47c8f9();
            eax = var_7C;
            *0x0 = var_C;
            &decomp_var_b4 = ebp;
    }
    else {
            eax = sub_4060c0(var_C4, decomp_var_c0, decomp_var_bc, decomp_var_b8, decomp_var_b4, var_B0, var_AC, var_A8, var_A4, var_A0, var_9C, var_98, var_94, var_90, var_8C, var_88, var_84, var_80, var_7C, ebx + 0x10);
    }
    return eax;

loc_406265:
    ebx = var_AC;
    if (esi == 0x0 || esi != &var_B0) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == 0x0) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_404fd0(&var_1C, edi + 0xc, var_C4);
            sub_40f400();
            edi = var_88;
            esi = var_8C;
            continue;
    }
    break;
    eax = sub_405190(&var_5C, &var_B0, *var_AC, &var_B0, var_AC);
    esp = esp - 0x18;
    eax = sub_4025d0(&var_A4);
    eax = var_A0;
    ebx = eax[0x1];
    esi = ebx;
    if (ebx[0x15] == 0x0) {
            do {
                    sub_4019f0(esi[0x2]);
                    esi = *esi;
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    ebx = esi;
            } while (esi[0x15] == 0x0);
            eax = var_A0;
    }
    eax[0x1] = eax;
    var_9C = 0x0;
    *var_A0 = var_A0;
    var_A0[0x2] = var_A0;
    if (var_B1 == 0x0) {
            continue;
    }
    temp_1 = 0x1;
    break;
}
