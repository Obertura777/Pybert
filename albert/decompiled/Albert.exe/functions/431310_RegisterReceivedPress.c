// RegisterReceivedPress @ 0x431310
// hopper name: sub_431310
// pybert name: RegisterReceivedPress
// referenced by: called
// source: REA batch_decompile (Hopper) evidence ev_84a29276878deed2f6f82f4902efd1af3068bd2f0c5f74171e6c8513865ea0d2
// binary: Albert.exe sha256 449dec83b23974401cd47afa83532c3e3747681d24a4c96f780d5afd985e4dfb

RegisterReceivedPress() {
    var_8 = sub_496e70;
    var_C = *0x0;
    var_20C = edi;
    decomp_var_210 = *dword_4c8db8 ^ &var_20C;
    *0x0 = &var_C;
    var_1E8 = ecx;
    sub_422960();
    eax = sub_465f60(&arg_0);
    ebx = arg_10;
    var_1FC = ebx & 0xff;
    edi = sub_465930();
    esp = esp - 0x21c;
    eax = sub_404ce0(&var_1F4, &var_1FC, decomp_var_210);
    esi = 0x0;
    if (edi > 0x0) {
            eax = sub_465900(&var_1FC, esi);
            edx = *(int8_t *)eax & 0xff;
            esp = esp - 0x10;
            var_1F8 = edx;
            eax = sub_404ce0(&var_1F4, &var_1F8, decomp_var_210);
            esi = esi + 0x1;
            if (esi < edi) {
                    continue;
            }
            break;
    }
    var_218 = &var_1E4;
    var_1D0 = 0x0;
    sub_465ff0(sub_466f80(var_218, 0xbc1e0c));
    sub_465fa0();
    sub_465ff0(&var_100);
    var_214 = &arg_14;
    sub_465ff0(var_214);
    var_1F8 = &decomp_var_21c;
    sub_4220e0(&arg_24);
    sub_465f60(&arg_14);
    decomp_var_230 = ecx;
    decomp_var_230 = ebx;
    sub_465f60(&arg_0);
    var_4 = 0x4;
    var_22C = sub_426140(var_240, decomp_var_23c, decomp_var_238, decomp_var_234, decomp_var_230, var_22C, decomp_var_228, var_224, var_220, decomp_var_21c, var_218);
    sub_410cf0(var_1E8[0x1]);
    var_1E8[0x1] = var_1E8;
    var_1E4 = 0x0;
    *var_1E8 = var_1E8;
    var_1E8[0x2] = var_1E8;
    sub_410cf0(var_1DC[0x1]);
    var_1DC[0x1] = var_1DC;
    var_1D8 = 0x0;
    *var_1DC = var_1DC;
    var_1DC[0x2] = var_1DC;
    sub_47b26f(0x0);
    esi = &var_8;
    edi = *(int32_t *)0x4;
    esp = (esp - 0x5c) + 0x4;
    &var_240 = &var_240;
    goto loc_431570;

loc_431570:
    ebp = 0x0;
    ebx = var_4;
    if (esi == 0x0 || esi != &var_8) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == ebp) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x1c] == 0x1) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
            }
            else {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
            }
            sub_419300(var_214, decomp_var_210, var_20C);
            sub_40f6f0();
            edi = var_1EC;
            esi = var_1F0;
            continue;
    }
    break;
    ebp = 0x0;
    edx = var_218[0x2];
    eax = 0x0;
    if (edx[0x901] > 0x0) {
            do {
                    ecx = var_22C;
                    if (ecx == ebp) {
                            *(&var_240 + eax * 0x4 + 0x6c) = ebp;
                    }
                    else {
                            *(&var_240 + eax * 0x4 + 0x6c) = ecx;
                    }
                    eax = eax + 0x1;
            } while (eax < edx[0x901]);
    }
    var_E0 = *dword_bb65f4;
    sub_4222a0(&var_1D0);
    esp = esp - 0xc;
    eax = sub_430480(&var_1E0, &var_E0, var_20C);
    sub_41cc50();
    eax = var_1B4;
    esi = eax[0x1];
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = var_1B4;
    }
    eax[0x1] = eax;
    *var_1B4 = var_1B4;
    var_1B4[0x2] = var_1B4;
    eax = var_1A8;
    esi = eax[0x1];
    edi = esi;
    if (esi[0x1d] == 0x0) {
            do {
                    sub_410cf0(edi[0x2]);
                    edi = *edi;
                    sub_465fa0();
                    sub_47c8f9();
                    esp = (esp - 0x8) + 0x4;
                    esi = edi;
            } while (edi[0x1d] == 0x0);
            eax = var_1A8;
    }
    eax[0x1] = eax;
    var_1A4 = ebp;
    *var_1A8 = var_1A8;
    var_1A8[0x2] = var_1A8;
    edi = *arg_2c;
    esi = &arg_28;
    &var_20C = &var_20C;
    goto loc_431760;

loc_431760:
    ebx = arg_2c;
    if (esi == ebp || esi != &arg_28) {
            sub_47a948();
    }
    if (edi != ebx) {
            if (esi == ebp) {
                    sub_47a948();
            }
            if (edi == esi[0x1]) {
                    sub_47a948();
            }
            if (edi[0x1c] == 0x0) {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
            }
            else {
                    if (edi == esi[0x1]) {
                            sub_47a948();
                    }
                    esp = esp - 0x8;
            }
            sub_419300(var_1E0, var_1DC, var_1D8);
            sub_40f6f0();
            edi = var_1B8;
            esi = var_1BC;
            continue;
    }
    break;
    ecx = var_1E4[0x2];
    eax = 0x0;
    if (ecx[0x901] > ebp) {
            do {
                    edi = var_1F8;
                    if (edi == ebp) {
                            *(&var_20C + eax * 0x4 + 0x6c) = ebp;
                    }
                    else {
                            *(&var_20C + eax * 0x4 + 0x6c) = edi;
                    }
                    eax = eax + 0x1;
            } while (eax < ecx[0x901]);
    }
    else {
            edi = var_1F8;
    }
    esi = *dword_bb65f4;
    var_78 = esi;
    sub_4222a0(&var_168);
    sub_430480(&var_178, &var_78, var_1A4);
    sub_41cc50();
    *dword_baed60 = esi;
    sub_465fa0();
    sub_41cc50();
    sub_465fa0();
    sub_465fa0();
    sub_41abc0(&var_188, &arg_90, *arg_94, &arg_90, arg_94);
    sub_47c8f9();
    eax = edi;
    *0x0 = arg_5C;
    return eax;
}
