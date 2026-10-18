// sub_433510 @ 0x433510
// hopper name: sub_433510
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

sub_433510() {
    var_C = *0x0;
    var_C4 = ebx;
    var_C8 = ebp;
    var_CC = esi;
    decomp_var_d0 = edi;
    esp = esp - 0xd4;
    decomp_var_d4 = *dword_4c8db8 ^ &decomp_var_d0;
    *0x0 = &var_C;
    var_9C = ecx;
    var_BD = 0x0;
    var_BC = 0x0;
    var_B8 = 0x0;
    var_BE = 0x0;
    sub_465870();
    sub_465870();
    sub_465870();
    sub_465870();
    ecx = *(int8_t *)(ecx[0x2] + 0x2424) & 0xff;
    esi = **dword_bb65f0;
    edi = 0xbb65ec;
    var_A0 = ecx;
    var_AC = 0xbb65ec;
    goto loc_4335d0;

loc_4335d0:
    if (edi == 0x0 || edi != 0xbb65ec) {
            sub_47a948();
    }
    if (esi != *dword_bb65f0) {
            if (edi == 0x0) {
                    sub_47a948();
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x7] != 0x1) {
                    sub_40f470();
                    esi = var_C8;
                    edi = var_CC;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x27] <= 0x0) {
                    sub_40f470();
                    esi = var_C8;
                    edi = var_CC;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x18] != 0x1) {
                    sub_40f470();
                    esi = var_C8;
                    edi = var_CC;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            bool_1 = esi != edi[0x1];
            ebx = esi + 0x24;
            var_50 = esi[0xa];
            if (!bool_1) {
                    sub_47a948();
            }
            esp = esp - 0x8;
            eax = sub_401ff0(&var_24, &arg_0, decomp_var_d4, decomp_var_d0, var_CC);
            eax = *eax;
            if (eax == 0x0 || eax != ebx) {
                    sub_47a948();
            }
            if (arg_0 == var_50) {
                    sub_40f470();
                    esi = var_C8;
                    edi = var_CC;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            sub_465ff0(esi + 0xc0);
            esp = esp - 0xc;
            eax = sub_410980(&var_2C, &var_90, decomp_var_d4);
            eax = *eax;
            if (eax == 0x0 || eax != 0xbb6df4) {
                    sub_47a948();
            }
            if (arg_0 != *dword_bb6df8) {
                    sub_40f470();
                    esi = var_C8;
                    edi = var_CC;
                    continue;
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x27] > 0x0) {
                    eax = sub_40fa80();
                    esp = esp - 0x8;
                    eax = sub_4109f0(&var_78, eax + 0x8c, decomp_var_d4);
                    var_BC = *eax;
                    var_B8 = eax[0x1];
            }
            if (esi == edi[0x1]) {
                    sub_47a948();
            }
            if (esi[0x27] > 0x0) {
                    esp = esp - 0x4;
                    var_80 = 0xbb65ec;
                    eax = sub_40dfe0(&var_80);
                    if (eax == 0x0) {
                            ebx = var_A0;
                            if (*(sub_40fa80() + ebx * 0x4 + 0x38) == 0xfff0bdc0) {
                                    if (*(sub_40fa80() + arg_0 * 0x4 + 0x38) == 0xfff0bdc0) {
                                            ebp = *(sub_40fa80() + ebx * 0x4 + 0x38);
                                            esi = *(sub_40fa80() + arg_0 * 0x4 + 0x38);
                                    }
                                    else {
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            if (var_BC == 0x0) {
                                                    sub_47a948();
                                            }
                                            if (var_B8 == arg_0) {
                                                    sub_47a948();
                                            }
                                            ebp = *(esi + ebx * 0x4 + 0x48);
                                            ebp = ebp - *(var_B8 + ebx * 0x4 + 0x48);
                                            if (esi == edi[0x1]) {
                                                    sub_47a948();
                                            }
                                            if (var_B8 == var_BC[0x1]) {
                                                    sub_47a948();
                                            }
                                            esi = *(esi + arg_0 * 0x4 + 0x48);
                                            esi = esi - *(var_B8 + arg_0 * 0x4 + 0x48);
                                    }
                            }
                            else {
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    if (var_BC == 0x0) {
                                            sub_47a948();
                                    }
                                    if (var_B8 == arg_0) {
                                            sub_47a948();
                                    }
                                    ebp = *(esi + ebx * 0x4 + 0x48);
                                    ebp = ebp - *(var_B8 + ebx * 0x4 + 0x48);
                                    if (esi == edi[0x1]) {
                                            sub_47a948();
                                    }
                                    if (var_B8 == var_BC[0x1]) {
                                            sub_47a948();
                                    }
                                    esi = *(esi + arg_0 * 0x4 + 0x48);
                                    esi = esi - *(var_B8 + arg_0 * 0x4 + 0x48);
                            }
                    }
                    else {
                            ebx = var_A0;
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (var_BC == 0x0) {
                                    sub_47a948();
                            }
                            if (var_B8 == arg_0) {
                                    sub_47a948();
                            }
                            ebp = *(esi + ebx * 0x4 + 0x48);
                            ebp = ebp - *(var_B8 + ebx * 0x4 + 0x48);
                            if (esi == edi[0x1]) {
                                    sub_47a948();
                            }
                            if (var_B8 == var_BC[0x1]) {
                                    sub_47a948();
                            }
                            esi = *(esi + arg_0 * 0x4 + 0x48);
                            esi = esi - *(var_B8 + arg_0 * 0x4 + 0x48);
                    }
            }
            else {
                    ebx = var_A0;
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (var_BC == 0x0) {
                            sub_47a948();
                    }
                    if (var_B8 == arg_0) {
                            sub_47a948();
                    }
                    ebp = *(esi + ebx * 0x4 + 0x48);
                    ebp = ebp - *(var_B8 + ebx * 0x4 + 0x48);
                    if (esi == edi[0x1]) {
                            sub_47a948();
                    }
                    if (var_B8 == var_BC[0x1]) {
                            sub_47a948();
                    }
                    esi = *(esi + arg_0 * 0x4 + 0x48);
                    esi = esi - *(var_B8 + arg_0 * 0x4 + 0x48);
            }
            var_64 = &decomp_var_e0;
            var_AA = arg_4 & 0xff | 0x4100;
            sub_465f30(&var_AA);
            decomp_var_e4 = ecx;
            decomp_var_e4 = ebx & 0xff | 0x4100;
            var_90 = &decomp_var_f4;
            esp = esp - 0x2c;
            eax = sub_465f60(&var_8C);
            if (sub_422a90() != 0x0 || ebp <= 0x0) {
                    sub_40f470();
                    esi = var_C8;
                    edi = var_CC;
                    continue;
            }
            if (esi > 0xfffffce0) {
                    eax = esi + ebp;
                    if (eax > var_C4) {
                            var_C4 = eax;
                            sub_465ff0(&var_B0);
                            eax = sub_466f80(&var_3C, &var_B0);
                            esp = esp - 0x10;
                            sub_465ff0(eax);
                            var_24 = 0x3;
                            sub_465fa0();
                    }
            }
            sub_40f470();
            esi = var_C8;
            edi = var_CC;
            continue;
    }
    break;
    if (var_BE == 0x1) {
            var_B4 = arg_0 & 0xff | 0x4100;
            sub_465f30(&var_B4);
            sub_465ff0(&var_78);
            sub_465fa0();
            eax = sub_465f60(&var_64);
            eax = sub_465f60(&var_3C);
            sub_431940();
            esp = esp - 0x38;
            var_BD = 0x1;
            eax = sub_419300(&var_78, &var_4C, decomp_var_d4);
    }
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    sub_465fa0();
    eax = var_BD;
    *0x0 = var_C;
    return eax;
}
